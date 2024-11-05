#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

template<typename T>
string toString(const T& value) {
    ostringstream oss;
    oss << value;
    return oss.str();
}

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
    int left = 0, right = static_cast<int>(vec.size()) - 1;
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
    for (int i = 0; i < static_cast<int>(vec.size()); ++i) {
        if (vec[i] == target) return i;
    }
    return -1;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    vector<int> N_values = { 5000, 50000, 100000, 150000, 200000 }; // N

    for (int N : N_values) {
        double SumRBS = 0.0, SumIBS = 0.0, SumSeqS = 0.0;

        for (int i = 0; i < 10; ++i) {
            vector<int> vec(N);
            for (int& num : vec) {
                num = rand() % 100 + 1;
            }
            sort(vec.begin(), vec.end());
            int target = rand() % 100 + 1; 

            // Timing Recursive Binary Search
            auto start = chrono::high_resolution_clock::now();
            recursiveBinarySearch(vec, target, 0, static_cast<int>(vec.size()) - 1);
            auto end = chrono::high_resolution_clock::now();
            SumRBS += chrono::duration_cast<chrono::microseconds>(end - start).count();

            // Timing Iterative Binary Search
            start = chrono::high_resolution_clock::now();
            iterativeBinarySearch(vec, target);
            end = chrono::high_resolution_clock::now();
            SumIBS += chrono::duration_cast<chrono::microseconds>(end - start).count();

            // Timing Sequential Search
            start = chrono::high_resolution_clock::now();
            sequentialSearch(vec, target);
            end = chrono::high_resolution_clock::now();
            SumSeqS += chrono::duration_cast<chrono::microseconds>(end - start).count();
        }

        // Display
        cout << "For N = " << N << ":\n";
        cout << "Average Running Time for Recursive Binary Search in microseconds is " << (SumRBS / 10) << endl;
        cout << "Average Running Time for Iterative Binary Search in microseconds is " << (SumIBS / 10) << endl;
        cout << "Average Running Time for Sequential Search in microseconds is " << (SumSeqS / 10) << endl;
        cout << endl;
    }

    return 0;
}
