#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

constexpr int P = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    ll r = 0, s = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        r += s * a;
        r %= P;
        s += a;
        s %= P;
    }

    cout << r << endl;

    return 0;
}