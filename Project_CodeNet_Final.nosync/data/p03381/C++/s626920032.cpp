#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> x;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        x.push_back(a);
    }
    vector<int> y;
    y = x;
    sort(y.begin(), y.end());
    int mid = y[n/2];
    for (int i = 0; i < n; i++) {
        if (x[i] < mid) {
            cout << y[n/2] << endl;
        } else {
            cout << y[(n-1)/2] << endl;
        }
    }
    return 0;
}
