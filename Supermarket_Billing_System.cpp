#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class for grocery items
class GroceryItem
{
public:
    string name;
    double price;

    GroceryItem(string name, double price) : name(name), price(price) {}
};

// Grocery management class
class GroceryStore
{
private:
    vector<GroceryItem> items;

public:
    GroceryStore()
    {
        // Initialize store with grocery items and prices in rupees
        items.push_back(GroceryItem("Apple", 150.0));
        items.push_back(GroceryItem("Banana", 40.0));
        items.push_back(GroceryItem("Carrot (1kg)", 60.0));
        items.push_back(GroceryItem("Potato (1kg)", 40.0));
        items.push_back(GroceryItem("Rice (1kg)", 80.0));
        items.push_back(GroceryItem("Wheat Flour (1kg)", 50.0));
        items.push_back(GroceryItem("Onion (1kg)", 50.0));
        items.push_back(GroceryItem("Tomato (1kg)", 60.0));
        items.push_back(GroceryItem("Milk (1L)", 50.0));
        items.push_back(GroceryItem("Eggs (12 pack)", 70.0));
        items.push_back(GroceryItem("Sugar (1kg)", 45.0));
        items.push_back(GroceryItem("Salt (1kg)", 20.0));
        items.push_back(GroceryItem("Green Beans (1kg)", 100.0));
        items.push_back(GroceryItem("Spinach (1kg)", 40.0));
        items.push_back(GroceryItem("Butter (500g)", 150.0));
        items.push_back(GroceryItem("Cheese (500g)", 200.0));
        items.push_back(GroceryItem("Yogurt (500g)", 60.0));
        items.push_back(GroceryItem("Cucumber", 30.0));
        items.push_back(GroceryItem("Garlic (250g)", 35.0));
        items.push_back(GroceryItem("Ginger (250g)", 50.0));
    }

    void displayStore()
    {
        cout << "\nGROCERY STORE:\n";
        for (size_t i = 0; i < items.size(); i++)
        {
            cout << i + 1 << ". " << items[i].name << " - Rs." << items[i].price << endl;
        }
        cout << "0. Checkout\n";  // Change exit option to "Checkout"
    }

    void addItem(string name, double price)
    {
        items.push_back(GroceryItem(name, price));
        cout << "Item added successfully!\n";
    }

    void removeItem(int index)
    {
        if (index >= 0 && index < items.size())
        {
            items.erase(items.begin() + index);
            cout << "Item removed successfully!\n";
        }
        else
        {
            cout << "Invalid item number!\n";
        }
    }

    void editItemPrice(int index, double newPrice)
    {
        if (index >= 0 && index < items.size())
        {
            items[index].price = newPrice;
            cout << "Price updated successfully!\n";
        }
        else
        {
            cout << "Invalid item number!\n";
        }
    }

    const vector<GroceryItem>& getItems() const
    {
        return items;
    }
};

// Customer class
class Customer
{
public:
    void shop(GroceryStore& store)
    {
        double totalBill = 0;
        int choice;

        do
        {
            store.displayStore();
            cout << "\nChoose an item number to add to your cart (or 0 to Checkout): ";
            cin >> choice;

            if (choice > 0 && choice <= store.getItems().size())
            {
                totalBill += store.getItems()[choice - 1].price;
                cout << store.getItems()[choice - 1].name << " added to your cart.\n";
            }
            else if (choice == 0)
            {
                cout << "\nTotal bill: Rs." << totalBill << endl;
                cout << "Thank you for shopping! Checkout successful.\n";
            }
            else
            {
                cout << "Invalid choice!\n";
            }

        }
        while (choice != 0);
    }
};

// Shop owner class
class ShopOwner
{
private:
    string password = "owner123";

    bool authenticate()
    {
        string input;
        cout << "Enter password: ";
        cin >> input;
        return input == password;
    }

public:
    void manageStore(GroceryStore& store)
    {
        if (!authenticate())
        {
            cout << "Incorrect password! Access denied.\n";
            return;
        }

        int choice;
        do
        {
            cout << "\n1. Add Item\n2. Remove Item\n3. Edit Item Price\n4. View Store\n0. Exit\nChoose an option: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                string name;
                double price;
                cout << "Enter item name: ";
                cin >> name;
                cout << "Enter item price: Rs.";
                cin >> price;
                store.addItem(name, price);
                break;
            }
            case 2:
            {
                int index;
                store.displayStore();
                cout << "Enter item number to remove: ";
                cin >> index;
                store.removeItem(index - 1);
                break;
            }
            case 3:
            {
                int index;
                double price;
                store.displayStore();
                cout << "Enter item number to edit: ";
                cin >> index;
                cout << "Enter new price: Rs.";
                cin >> price;
                store.editItemPrice(index - 1, price);
                break;
            }
            case 4:
                store.displayStore();
                break;
            case 0:
                cout << "Exiting store management...\n";
                break;
            default:
                cout << "Invalid choice!\n";
            }
        }
        while (choice != 0);
    }
};

// Main program
int main()
{
    GroceryStore store;
    Customer customer;
    ShopOwner owner;

    int role;
    do
    {
        cout << "\n1. Customer\n2. Shop Owner\n0. Exit\nChoose your role: ";
        cin >> role;

        switch (role)
        {
        case 1:
            customer.shop(store);
            break;
        case 2:
            owner.manageStore(store);
            break;
        case 0:
            cout << "Exiting the system...\n";
            break;
        default:
            cout << "Invalid role!\n";
        }
    }
    while (role != 0);

    return 0;
}
