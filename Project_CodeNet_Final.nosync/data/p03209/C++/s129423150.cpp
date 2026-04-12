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
    int n;
    cin >> n;

    ll x;
    cin >> x;

    ll a[51] = { 1 }, b[51] = { 1 };
    for (int i = 0; i < n; i++) {
        a[i + 1] = a[i] * 2 + 3;
        b[i + 1] = b[i] * 2 + 1;
    }

    ll r = 0;
    for (int i = n; i > 0; i--) {
        if (x < 1) {
            break;
        } else if (x < 1 + a[i - 1]) {
            x--;
        } else if (x < 1 + a[i - 1] + 1) {
            r += b[i - 1];
            break;
        } else if (x < a[i] - 1) {
            r += b[i - 1] + 1;
            x -= 1 + a[i - 1] + 1;
        } else {
            r += b[i];
            break;
        }
    }

    cout << r << endl;

    return 0;
}