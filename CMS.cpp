#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

class Cafe {
private:
    map<string, int> menuItems;
    vector<string> orders;
    map<string, int> orderQuantities;
    
    string toLower(const string& str) {
        string lowerStr = str;
        transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
        return lowerStr;
    }

public:
    Cafe() {
        menuItems = {
            {"cold coffee", 50},
            {"hazelnut coffee", 100},
            {"hot coffee", 20},
            {"chocolate shake", 60},
            {"brownie shake", 70},
            {"butterscotch shake", 50},
            {"onion pizza", 80},
            {"sweet corn pizza", 80},
            {"otc pizza", 150},
            {"steamed momos", 70},
            {"fried momos", 80},
            {"tandoori momos", 100},
            {"red sauce pasta", 80},
            {"white sauce pasta", 70},
            {"pink sauce pasta", 150}
        };
    }

    void displayMenu() {
        cout << "BEVERAGES\n";
        cout << "__________\n";
        cout << "1. Cold Coffee       50\n";
        cout << "2. Hazelnut Coffee  100\n";
        cout << "3. Hot Coffee        20\n";
        cout << "------------------------------\n";
        cout << "SHAKES\n";
        cout << "__________\n";
        cout << "4. Chocolate Shake   60\n";
        cout << "5. Brownie Shake     70\n";
        cout << "6. Butterscotch Shake 50\n";
        cout << "------------------------------\n";
        cout << "PIZZA\n";
        cout << "__________\n";
        cout << "7. Onion Pizza       80\n";
        cout << "8. Sweet Corn Pizza  80\n";
        cout << "9. OTC Pizza        150\n";
        cout << "------------------------------\n";
        cout << "MOMOS\n";
        cout << "__________\n";
        cout << "10. Steamed Momos    70\n";
        cout << "11. Fried Momos      80\n";
        cout << "12. Tandoori Momos  100\n";
        cout << "------------------------------\n";
        cout << "PASTA\n";
        cout << "__________\n";
        cout << "13. Red Sauce Pasta  80\n";
        cout << "14. White Sauce Pasta 70\n";
        cout << "15. Pink Sauce Pasta 150\n";
        cout << "------------------------------\n";
    }

    void takeOrder() {
        string item;
        char more = 'y';
        if (!orders.empty()) {
            char p;
            show:
            cout << "Press A to add new items to orders\nPress V to view old orders\nPress B to go back\n";
            cin >> p;
            if (p == 'A' || p == 'a') {
                goto Take;
            } else if (p == 'v' || p == 'V') {
                cout << "Your Orders Are -\n";
                for (int i = 0; i < orders.size(); i++) {
                    cout << i + 1 << ". " << orders[i] << endl;
                }
                int x;
                cout << "Press 0 to exit and 1 to continue\n";
                cin >> x;
                if (x == 1) {
                    goto show;
                } else if (x == 0) {
                    exit(0);
                }
            } else if (p == 'b' || p == 'B') {
                display();
            } else if (p != 'a' || p != 'A') {
                cout << "Wrong Choice";
                exit(0);
            }
        }
        Take:
        while (more == 'y' || more == 'Y') {
            cout << "Enter your chosen item: ";
            cin.ignore();
            getline(cin, item);
            string itemLower = toLower(item);

            if (menuItems.find(itemLower) != menuItems.end()) {
                orders.push_back(itemLower);
                orderQuantities[itemLower]++;
                cout << "Item added to order." << endl;
            } else {
                cout << "Invalid item. Please choose from the menu." << endl;
            }

            cout << "Do you want to add more items? (y/n): ";
            cin >> more;
        }
    }

    void generateBill() {
        int total = 0;
        cout << "BILL\n";
        cout << "_____________________\n";
        for (const auto& order : orders) {
            int price = menuItems[order];
            int quantity = orderQuantities[order];
            total += price * quantity;
            cout << order << " x " << quantity << " = " << price * quantity << endl;
        }
        cout << "-----------------------\n";
        cout << "Total: " << total << endl;
    }

    void display() {
        int choice;
        cout << "Enter your choice\n";
        cout << "1. Menu Card\n2. Orders\n3. Bill\nPress 0 To Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            displayMenu();
            break;
        case 2:
            takeOrder();
            break;
        case 3:
            generateBill();
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please enter a valid number." << endl;
            break;
        }
    }
};

int main() {
    Cafe c;
    cout << "WELCOME TO THE A&A RESTAURANT\n";
    cout << "------------------------------\n";
    while (1) {
        c.display();
    }
    return 0;
}
