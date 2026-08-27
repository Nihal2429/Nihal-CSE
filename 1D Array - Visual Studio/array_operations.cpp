#include <iostream>
using namespace std;

int main() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n < 0 || n > MAX_SIZE) {
        cout << "Invalid size. Enter a size between 0 and 100.\n";
        return 0;
    }

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nOriginal Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    int pos, value;

    // Insertion
    cout << "\n\nEnter position for insertion (1-" << n + 1 << "): ";
    cin >> pos;

    cout << "Enter value to insert: ";
    cin >> value;

    if (pos < 1 || pos > n + 1) {
        cout << "Invalid insertion position.\n";
        return 0;
    }

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = value;
    n++;

    cout << "After Insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Deletion
    cout << "\n\nEnter position for deletion (1-" << n << "): ";
    cin >> pos;

    if (pos < 1 || pos > n) {
        cout << "Invalid deletion position.\n";
        return 0;
    }

    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "After Deletion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Traversal
    cout << "\n\nFinal Array (Traversal): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;
}