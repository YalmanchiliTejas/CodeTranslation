#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
ll mod = 1000000007;

int num(char c) { return c - '0'; }
int main() {
source:
    string n;
    ll k;
    cin >> n >> k;
    int len = n.length();
    ll x[len][3], y[len];
    x[0][1] = num(n[0]) - 1;
    x[0][2] = 0;
    x[0][3] = 0;
    y[0] = 1;
    repd(i, 1, len) {
        int temp = num(n[i]);
        x[i][1] = x[i - 1][1] + 9;
        x[i][2] = x[i - 1][2] + x[i - 1][1] * 9;
        x[i][3] = x[i - 1][3] + x[i - 1][2] * 9;
        if (temp != 0) {
            y[i] = y[i - 1] + 1;
            if (y[i - 1] == 1) {
                x[i][1] += 1;
                x[i][2] += temp - 1;
            } else if (y[i - 1] == 2) {
                x[i][2] += 1;
                x[i][3] += temp - 1;
            } else if (y[i - 1] == 3) {
                x[i][3] += 1;
            }
        } else {
            y[i] = y[i - 1];
        }
    }

    int last = y[len - 1];
    if (last <= 3) {
        x[len - 1][last]++;
    }

    cout << x[len - 1][k] << endl;
    return 0;
}

