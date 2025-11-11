#include <iostream>
using namespace std;

#define SIZE 10  // Size of hash table

class HashTable {
    int table[SIZE];

public:
    // Constructor - initialize table with -1 (empty)
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    // Hash function
    int hashFunction(int key) {
        return key % SIZE;
    }

    // Insert a value using linear probing
    void insert(int key) {
        int index = hashFunction(key);

        // If collision occurs, use linear probing
        int startIndex = index;
        while (table[index] != -1) {
            index = (index + 1) % SIZE;
            if (index == startIndex) {
                cout << "Hash table is full!\n";
                return;
            }
        }
        table[index] = key;
    }

    // Search a value
    bool search(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1) {
            if (table[index] == key)
                return true;
            index = (index + 1) % SIZE;
            if (index == startIndex)
                return false;
        }
        return false;
    }

    // Display the hash table
    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << " --> ";
            if (table[i] != -1)
                cout << table[i];
            else
                cout << "empty";
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;

    do {
        cout << "\n1. Insert\n2. Search\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            break;

        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            if (ht.search(key))
                cout << key << " found in the hash table.\n";
            else
                cout << key << " not found.\n";
            break;

        case 3:
            ht.display();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

