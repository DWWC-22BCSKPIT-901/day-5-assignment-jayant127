#include <iostream>
#include <vector>
using namespace std;

int findFirstOccurrence(int k, vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == k) {
            return i + 1; // Return 1-based index
        }
    }
    return -1; // If k is not found
}

int main() {
    // Example 1
    int k1 = 16;
    vector<int> arr1 = {9, 7, 16, 16, 4};
    cout << findFirstOccurrence(k1, arr1) << endl;

    // Example 2
    int k2 = 98;
    vector<int> arr2 = {1, 22, 57, 47, 34, 18, 66};
    cout << findFirstOccurrence(k2, arr2) << endl;

    // Example 3
    int k3 = 9;
    vector<int> arr3 = {1, 22, 57, 47, 34, 9, 66};
    cout << findFirstOccurrence(k3, arr3) << endl;

    return 0;
}
