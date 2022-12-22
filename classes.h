#include <bits/stdc++.h>
using namespace std;
class Item;
class Cart;
class Product
{
    int id;
    string name;
    int price;
    public:
    Product(){}
    Product(int u_id, string name, int price)
    {
        id = u_id;
        this->name = name;
        this->price = price;
    }
    string getdisplayitem()
    {
        return name+" Rs "+ to_string(price)+"\n";
    }
    string getshortname()
    {
        return name.substr(0, 1);
    }
    
    friend class Item;
    friend class Cart;
};

class Item
{
    Product product;
    public:
    int quantity;
    Item(){}
    Item(Product p, int q): product(p), quantity(q){}
    int getitemprice()
    {
        return quantity*product.price;
    }
    string getiteminfo()
    {
        return to_string(quantity) + " x " + product.name+ " Rs."+to_string(getitemprice())+ "\n";
    }
    friend class Cart;
};
class Cart
{
    unordered_map<int, Item> carts;
    public:
    void addproduct(Product product)
    {
        if(carts.count(product.id)==0)
        {
            Item newItem(product , 1);
            carts[product.id] = newItem;
        }
        else
        {
            carts[product.id].quantity+=1;
        }
    }
    int gettotal()
    {
        int total = 0;
        for(auto itempair: carts)
        {
            auto item = itempair.second;
            total+=item.getitemprice();
        }
        return total;
    }
    string viewcart()
    {
        if(carts.empty())
        {
            return "Cart is empty";
        }
        string itemizedlist;
        int cart_total = gettotal();
        for(auto itempair: carts)
        {
            auto item = itempair.second;
            itemizedlist.append(item.getiteminfo());
        }
        return itemizedlist + "\nTotal Amount: Rs."+to_string(cart_total)+" \n";
    }
    bool isempty()
    {
        return carts.empty();
    }

};