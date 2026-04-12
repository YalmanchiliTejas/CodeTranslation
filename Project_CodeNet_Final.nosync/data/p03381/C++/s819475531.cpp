#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b;
    b = a;

    sort(a.begin(), a.end());
    int k = n / 2;
    int x = a[k - 1], y = a[k];

    for (int i = 0; i < n; i++) {
        cout << (b[i] <= x ? y : x) << '\n';
    }

    cout << flush;

    return 0;
}