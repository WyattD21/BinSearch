#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

// Recursive Binary Search
int recursiveBinarySearch(const vector<int>& vec, int target, int left, int right) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (vec[mid] == target) return mid;
    if (vec[mid] > target) return recursiveBinarySearch(vec, target, left, mid - 1);
    return recursiveBinarySearch(vec, target, mid + 1, right);
}

// Iterative Binary Search
int iterativeBinarySearch(const vector<int>& vec, int target) {
    int left = 0, right = vec.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target) return mid;
        if (vec[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Sequential Search
int sequentialSearch(const vector<int>& vec, int target) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) return i;
    }
    return -1;
}

int main() {
    vector<int> vec = { 3, 5, 8, 12, 15, 20, 25, 30 }; //data
    sort(vec.begin(), vec.end());
    int target1 = 15; // Test vals
    int target2 = 100; // 

    // Recursive Binary Search
    int index = recursiveBinarySearch(vec, target1, 0, vec.size() - 1);
    cout << target1 << (index != -1 ? " found at location " : " was not found, return value is ") << index << endl;

    index = recursiveBinarySearch(vec, target2, 0, vec.size() - 1);
    cout << target2 << (index != -1 ? " found at location " : " was not found, return value is ") << index << endl;

    // Iterative Binary Search
    index = iterativeBinarySearch(vec, target1);
    cout << target1 << (index != -1 ? " found at location " : " was not found, return value is ") << index << endl;

    index = iterativeBinarySearch(vec, target2);
    cout << target2 << (index != -1 ? " found at location " : " was not found, return value is ") << index << endl;

    // Sequential Search
    index = sequentialSearch(vec, target1);
    cout << target1 << (index != -1 ? " found at location " : " was not found, return value is ") << index << endl;

    index = sequentialSearch(vec, target2);
    cout << target2 << (index != -1 ? " found at location " : " was not found, return value is ") << index << endl;

    return 0;
}
