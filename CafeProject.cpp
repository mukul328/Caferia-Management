#include<iostream>
#include<vector>
using namespace std;

class Menu {
    private:
        string item;
        int price, itemNo;
    public:
        Menu(int ItemNo, string Item, int Price) {
            itemNo = ItemNo;
            item = Item;
            price = Price;
        }

        string getItem() {
            return item;
        }

        int getItemNo() {
            return itemNo;
        }

        int getPrice() {
            return price; 
        }
};

class Cafe {
    private:
        vector<Menu> ve;
    public:
        void add(int ItemNo, string Item, int Price) {
            Menu menu(ItemNo, Item, Price);
            ve.push_back(menu);
        }

        void order() {
            for (int i = 0; i < ve.size(); i++) {
                cout << ve[i].getItemNo() << ". " << ve[i].getItem() << ": " << ve[i].getPrice() << endl;   
            }
            int ord, quant;
            cout << "Enter Item no for Order: "; cin >> ord;
            cout << "Enter Quantity of Item: "; cin >> quant;
            
            for (int i = 0; i < ve.size(); i++) {
                if (ord == ve[i].getItemNo()) {
                    int total = quant * ve[i].getPrice();
                    cout << "Your Total Bill is: " << total << endl;
                }
            }
        }
};

int main() {
    Cafe cafe;
    cafe.add(1, "Paneer Butter Masala", 249);
    cafe.add(2, "Vada Pav", 99);
    cafe.add(3, "Pav Bhaji", 339);
    cafe.add(4, "Veg Burger", 249);
    cafe.add(5, "Virgin Mojito", 149);
    cafe.add(6, "Hot Coffee", 119);
    cafe.add(7, "Cold Coffee", 149);
    cafe.add(8, "Tomato Omelette", 249);
    cafe.add(9, "Chilli Potato", 299);
    cafe.add(10, "Veg Hakka Noodles", 249);
    
    cout << "<<<<< CAFETERIA MENU >>>>>" << endl << endl;
    cafe.order();

    return 0;
}
