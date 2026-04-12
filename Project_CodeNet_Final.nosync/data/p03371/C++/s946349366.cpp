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
    ll AB_SUM = A*X+B*Y;
    ll C_SUM = C*max(X, Y)*2;
    bool flg = false;
    if (X > Y) flg = true;
    ll MIX_SUM = C*min(X, Y)*2 + abs(X-Y)*(flg ? A : B);
    cout << min(min(AB_SUM, C_SUM), MIX_SUM) << endl;
    return 0;
}