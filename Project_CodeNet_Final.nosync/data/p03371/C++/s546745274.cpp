#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll A, B, C, X, Y;
    ll mini = LONG_LONG_MAX;
    cin >> A >> B >> C >> X >> Y;
    for(ll i = 0;i <= 100000;i++) {
        ll temp = 2 * C * i + A * max(0LL, X - i) + B * max(0LL, Y - i);
        mini = min(temp, mini);
    }
    cout << mini << endl;
    return 0;
}
