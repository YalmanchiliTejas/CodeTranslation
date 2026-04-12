#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    pair<int, int> x[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i].first;
        x[i].second = i;
    }
    sort(x, x + n);
    int index[n];
    for (int i = 0; i < n; i++) {
        index[x[i].second] = i;
    }
    for (int i = 0; i < n; i++) {
        if (index[i] < n / 2) {
            cout << x[n / 2].first << ' ';
        } else {
            cout << x[n / 2 - 1].first << ' ';
        }
    }
    return 0;
}