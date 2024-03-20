#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Customer {
    string name;
    long long phone;
    string pin;
    int slot;
    Customer(string n, long long m, string p, int a) : name(n), phone(m), pin(p), slot(a) {}
};

void displayMenu();
void viewParkingLot(int arr[3][10]);
int findEmptySlot(int arr[3][10]);

int main() {
    unordered_map<int, Customer*> twoWheelerMap;
    unordered_map<int, Customer*> fourWheelerMap;
    int twoWheelerParking[3][10] = {0};
    int fourWheelerParking[3][10] = {0};

    int flag = 0;
    while (flag == 0) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int slot = findEmptySlot(twoWheelerParking);
                if (slot == 0) {
                    cout << "Sorry! No space available for parking." << endl;
                    break;
                }

                int vehicleNo;
                cout << "Enter your vehicle number: ";
                cin >> vehicleNo;
                string name;
                cout << "Enter your name: ";
                cin >> name;
                long long phone;
                cout << "Enter your phone number: ";
                cin >> phone;
                
                string pin = "2" + to_string(vehicleNo) + to_string(slot);

                Customer* customer = new Customer(name, phone, pin, slot);
                twoWheelerMap[vehicleNo] = customer;

                int row = (slot - 1) / 10;
                int col = (slot - 1) % 10;
                twoWheelerParking[row][col] = 1;

                cout << "Your vehicle parking pin is: " << pin << endl;
                cout << "Please park your vehicle at slot " << char('A' + row) << col + 1 << endl;
                break;
            }
            case 7: {
                flag = 1;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
    return 0;
}

void displayMenu() {
    cout << "===== Parking Management System =====" << endl;
    cout << "1. Park 2 wheeler" << endl;
    cout << "2. Park 4 wheeler" << endl;
    cout << "3. Leave from 2 wheeler" << endl;
    cout << "4. Leave from 4 wheeler" << endl;
    cout << "5. Print ticket" << endl;
    cout << "6. Get an overview of parking lot (admins only)" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

void viewParkingLot(int arr[3][10]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int findEmptySlot(int arr[3][10]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] == 0) {
                return (i + 1) * 10 + (j + 1);
            }
        }
    }
    return 0;
}
