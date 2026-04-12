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

ll rec(int n, ll x) {
    if (n == 0) return 1;
    ll len = (1LL<<(n+1)) - 3;
    ll num = (1LL<<n) - 1;
    if (x == 1) return 0;
    else if (x <= len + 1) return rec(n - 1, x - 1);
    else if (x == len + 2) return num + 1;
    else if (x <= (len + 1) * 2) return num + 1 + rec(n - 1, x - len - 2);
    else return num * 2 + 1;
}

int main()
{
    int n; ll x;
    cin >> n >> x;

    cout << rec(n, x) << endl;
    return 0;
}