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
    int n;
    cin >> n;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    multiset<ll> s;

    rep(i, n) {
        ll now = a[i];
        auto itr = s.lower_bound(now);
        if (itr != s.begin()) s.erase(--itr);
        s.insert(now);
    }

    cout << s.size() << endl;

    return 0;
}