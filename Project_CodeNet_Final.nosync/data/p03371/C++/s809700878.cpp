#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define inf 1e9
#define INF 1000000000000000000
#define PI 3.14159265359

int main() {
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    if (A + B > C * 2) {
        if (X > Y) {
            cout << min(X * 2 * C, Y * 2 * C + (X - Y) * A) << endl;
        } else {
            cout << min(Y * 2 * C, X * 2 * C + (Y - X) * B) << endl;
        }
    } else {
        cout << A * X + B * Y << endl;
    }
}