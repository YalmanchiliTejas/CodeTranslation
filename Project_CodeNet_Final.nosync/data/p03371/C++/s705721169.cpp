// https://qiita.com/e869120/items/eb50fdaece12be418faa

#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int res = INF;
    int sum = 0;

    for (int i = 0; i < max(x, y) * 2 + 1; i+=2) {
        sum += c * i;
        if (x > i / 2) sum += a * (x - i / 2);
        if (y > i / 2) sum += b * (y - i / 2);
        chmin(res, sum);
        sum = 0;
    }

    cout << res << endl;

    return 0;
}