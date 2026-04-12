#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll N;
    ll x, y;
    cin >> N;
    x = N * 800;
    y = (N / 15) * 200;
    cout << x - y << endl;
    return 0;
}
