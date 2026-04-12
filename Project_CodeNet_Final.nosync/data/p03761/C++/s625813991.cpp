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
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(26, INF);
    rep(i, n) {
        string s;
        cin >> s;
        vector<int> t(26, 0);
        rep(j, s.length()) {
            t[s[j] - 'a']++;
        }
        rep(i, 26) {
            chmin(a[i], t[i]);
        }
    }

    rep(i, 26) {
        if (a[i] == INF) continue;
        rep(j, a[i]) {
            cout << (char)('a' + i);
        }
    }

    cout << endl;

    return 0;
}