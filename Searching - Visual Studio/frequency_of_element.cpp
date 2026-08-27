#include <iostream>
using namespace std;

int main() {
    int arr[100], n, key, count = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element: ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            count++;
    }

    cout << "Frequency of " << key << " = " << count;

    return 0;
}