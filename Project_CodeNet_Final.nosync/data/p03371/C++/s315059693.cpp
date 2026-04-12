#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353
#define Graph vector<vector<int>>

int main() {
    ll A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    ll cost = 0;
    if (A + B < 2 * C) {
        cost = A * X + B * Y;
    }
    else {
        ll costa = C * 2 * max(X, Y);
        if (X < Y) {
            cost = C * 2 * X + B * (Y - X);
        }
        else {
            cost = C * 2 * Y + A * (X - Y);
        }
        cost = min(cost, costa);
    }
    cout << cost << endl;
}