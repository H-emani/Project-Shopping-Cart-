#include <bits/stdc++.h>
#include <graphics.h>
#include "classes.h"
using namespace std;
vector<Product> allproducts = {
    Product(3, "laptop", 10000),
    Product(4, "mouse", 1900),
    Product(10, "headphone", 900),
    Product(6, "smartphone", 2900),
    Product(12, "keyboard", 4100),
    Product(30, "printer", 45000),
    Product(17, "television", 30000),
    Product(25, "scanner", 43000),
    Product(26, "webcam", 4900),
};
Product * chooseProduct()
{
    string productlist;
    cout << "Available products " << endl;
    initwindow(688, 388, "Electronics Available");
    readimagefile("Electronics.jpg", 0, 0, 688, 388);
    getch();
    closegraph();
    for (auto Product : allproducts)
    {
        productlist.append(Product.getdisplayitem());
    }
    cout << productlist << endl;
    cout << "---------------------------" << endl;
    string choice;
    cin >> choice;
    for (int i = 0; i < allproducts.size(); i++)
    {
        if (allproducts[i].getshortname() == choice)
        {
            return &allproducts[i];
        }
    }
    cout << "Product not found! " << endl;
    return NULL;
}
bool checkout(Cart &cart)
{
    if (cart.isempty())
    {
        return false;
    }
    float total = cart.gettotal();
    cout << "Select the method of the payment - (c)ash, (o)nline" << endl;
    char action;
    cin >> action;
    //float total1;
    
    if (action == 'c')
    {
        if(total>50)
        {
            cout<<"Ohoo! you got the 50% off coupon "<<endl;
            total = total - 0.5*total;
        }
        int paid;
        cout << "Pay in cash " << endl;
        cout << "Total amount to be paid is: " << total<< endl;
        cin >> paid;
        if (paid >= total)
        {
            cout << "Change " << paid - total << endl;
            cout<<endl;
            cout << "Thankyou for shopping! " << endl;
            return true;
        }
        else
        {
            cout << "Not enough cash " << endl;
            return false;
        }
    }
    else
    {
        if(total>5000)
        {
            cout<<"Ohoo! you got the 50% off coupon "<<endl;
            total = total - 0.5*total;
        }
        cout << "Pay online " << endl;
        cout << "Total amount to be paid is: " << total << endl;
        int paid;
        cin >> paid;
        cout<<endl;
        cout << "Thankyou for shopping! " << endl<<endl;
        return true;
    }
}
int main()
{
    char action;
    Cart cart;
    cout<<endl<<endl;
    cout << "*****************ELECTRONICS DEVICES****************" << endl;
    cout<<endl;
    cout << "Great Indian Festive is going on order above 100, you will get 50% off on your order with no delivery charges, Hurry up" << endl;
    cout<<endl;
    cout << "Offer valid until 31st october " << endl<<endl;
    while (true)
    {
        cout << "Select an action - (a)dd item, (v)iew cart, (c)heckout " << endl;
        cin >> action;
        if (action == 'a')
        {
            Product *product = chooseProduct();
            if (product != NULL)
            {
                cout << "Added to the cart " << product->getdisplayitem() << endl;
                cart.addproduct(*product);
            }
        }
        else if (action == 'v')
        {
            cout << "------------------------" << endl;
            cout << cart.viewcart() << endl;
            cout << "-------------------------" << endl;
        }
        else
        {
            cart.viewcart();
            if (checkout(cart))
            {
                char flag;
                cout<<"Want to see the order summary "<<endl;
                cin>>flag;
                if(flag=='y')
                {
                    cout<<endl;
                    cout<<cart.viewcart();
                    cout<<"Status: Paid"<<endl;
                    cout<<"Deliver Today"<<endl;
                }
                break;
            }
        }
    }


    return 0;
}