Task 1: Resize Array
#include <iostream>
using namespace std;

int* resizeArray(int inArray[], const int size) {
    int* newArray = new int[size * 2];

    for (int i = 0; i < size; i++) {
        newArray[i] = inArray[i];
        newArray[i + size] = inArray[i] * 2;
    }

    return newArray;
}

int main() {
    int size;

    cout << "Enter size of array: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int* newArr = resizeArray(arr, size);

    cout << "Resized array: ";
    for (int i = 0; i < size * 2; i++) {
        cout << newArr[i] << " ";
    }

    delete[] arr;
    delete[] newArr;

    return 0;
}

#Task 2: Diagonal Matrix
#include <iostream>
using namespace std;

int main() {
    int n;
    bool diagonal = true;

    cout << "Enter matrix size: ";
    cin >> n;

    int matrix[20][20];

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && matrix[i][j] != 0) {
                diagonal = false;
            }
        }
    }

    if (diagonal)
        cout << "Diagonal Matrix";
    else
        cout << "Not Diagonal Matrix";

    return 0;
}

#Task 3: String and Substring
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[30];
    int count;

    cout << "Enter a string: ";
    cin.getline(str, 30);

    cout << "Enter count: ";
    cin >> count;

    if (count < 0 || count > strlen(str)) {
        cout << "Invalid count";
    }
    else {
        cout << "Substring: ";

        for (int i = 0; i < count; i++) {
            cout << str[i];
        }
    }

    return 0;
}

#Task 1: Inventory Item
#include <iostream>
#include <string>
using namespace std;

struct InventoryItem {
    int itemCode;
    string itemName;
    double cost;
    double sellingPrice;
};

int codeNumber = 31203;
int itemCount;

InventoryItem insertItem() {
    InventoryItem item;

    cout << "Enter item name: ";
    cin >> item.itemName;

    cout << "Enter cost: ";
    cin >> item.cost;

    item.itemCode = codeNumber++;
    item.sellingPrice = item.cost * 1.4;

    return item;
}

void displayStock(const InventoryItem* items) {
    cout << "\nCode\tName\tCost\tSelling Price\n";

    for (int i = 0; i < itemCount; i++) {
        cout << items[i].itemCode << "\t"
             << items[i].itemName << "\t"
             << items[i].cost << "\t"
             << items[i].sellingPrice << endl;
    }
}

int main() {
    InventoryItem items[10];

    cout << "Enter number of items (1-10): ";
    cin >> itemCount;

    if (itemCount < 1 || itemCount > 10) {
        cout << "Invalid number";
        return 0;
    }

    for (int i = 0; i < itemCount; i++) {
        items[i] = insertItem();
    }

    displayStock(items);

    return 0;
}
#Task 1 – Question 2
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct InventoryItem {
    string itemCode;
    string itemName;
    double cost;
    double sellingPrice;
};

int codeNumber = 31203;
int itemCount;

InventoryItem insertItem() {
    InventoryItem item;

    cout << "Enter item name: ";
    cin >> item.itemName;

    cout << "Enter cost: ";
    cin >> item.cost;

    string prefix = item.itemName.substr(0, 3);

    transform(prefix.begin(), prefix.end(),
              prefix.begin(), ::toupper);

    item.itemCode = prefix + "_" + to_string(codeNumber++);

    item.sellingPrice = item.cost * 1.4;

    return item;
}

void displayStock(const InventoryItem* items) {
    cout << "\nCode\tName\tCost\tSelling Price\n";

    for (int i = 0; i < itemCount; i++) {
        cout << items[i].itemCode << "\t"
             << items[i].itemName << "\t"
             << items[i].cost << "\t"
             << items[i].sellingPrice << endl;
    }
}

int main() {
    InventoryItem items[10];

    cout << "Enter number of items (1-10): ";
    cin >> itemCount;

    if (itemCount < 1 || itemCount > 10) {
        cout << "Invalid number";
        return 0;
    }

    for (int i = 0; i < itemCount; i++) {
        items[i] = insertItem();
    }

    displayStock(items);

    return 0;
}
#Task 2: Room Dimension
#include <iostream>
using namespace std;

struct RoomDimension {
    double length;
    double width;
};

double computeTheCarpetingCost(
    const RoomDimension& room) {

    return room.length * room.width * 18;
}

int main() {
    int n;

    cout << "Enter number of rooms: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number";
        return 0;
    }

    RoomDimension* rooms = new RoomDimension[n];

    double totalCost = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nRoom " << i + 1 << endl;

        cout << "Enter length: ";
        cin >> rooms[i].length;

        cout << "Enter width: ";
        cin >> rooms[i].width;

        double cost = computeTheCarpetingCost(rooms[i]);

        cout << "Room cost = " << cost << " Rs\n";

        totalCost += cost;
    }

    cout << "\nTotal carpeting cost = "
         << totalCost << " Rs";

    delete[] rooms;

    return 0;
}
