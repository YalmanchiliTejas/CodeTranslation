#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
        vector<int> s(n);
        for (auto &si: s) cin >> si;
        sort(s.begin(), s.end());
        int sum = accumulate(s.begin(), s.end(), 0) - s.front() - s.back();
        cout << sum / (n - 2) << endl;
    }
    return 0;
}
