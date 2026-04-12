#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000009;
const long long INF = 1LL << 60;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll res1 = A*X+B*Y;
    ll res2 = C*max(X, Y)*2;
    bool flg = false;
    if (X > Y) flg = true;
    ll res3 = C*min(X, Y)*2 + abs(X-Y) * (flg ? A : B);
    cout << min(min(res1, res2), res3) << endl;
    return 0;
}