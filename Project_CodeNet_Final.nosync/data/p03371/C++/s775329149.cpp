#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<string> vs;
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
const double PI = acos(-1.0);

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = INF;
    rep(i, max(X, Y) + 1) {
        ll tmp = A * max(X - i, 0) + B * max(Y - i, 0) + 2 * C * i;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}