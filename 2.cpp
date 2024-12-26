#include <iostream>
#include <vector>
using namespace std;

bool isPresent(const vector<int>& arr, int k) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids potential overflow

        if (arr[mid] == k) {
            return true; // k found
        } else if (arr[mid] < k) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return false; // k not found
}

int main() {
    // Example 1
    vector<int> arr1 = {1, 2, 3, 4, 6};
    int k1 = 6;
    cout << (isPresent(arr1, k1) ? "true" : "false") << endl;

    // Example 2
    vector<int> arr2 = {1, 2, 4, 5, 6};
    int k2 = 3;
    cout << (isPresent(arr2, k2) ? "true" : "false") << endl;

    // Example 3
    vector<int> arr3 = {1, 2, 4, 5, 6};
    int k3 = 6;
    cout << (isPresent(arr3, k3) ? "true" : "false") << endl;

    return 0;
}
