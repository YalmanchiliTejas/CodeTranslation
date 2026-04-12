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

    int h, w;
    cin >> h >> w;

    vector<int> eh(h);
    vector<int> ew(w);
    string s[h];
    rep(i, h) {
        cin >> s[i];
    }

    rep(i, h) {
        bool ok = true;
        rep(j, w) {
            if (s[i][j] == '#') ok = false;
        }
        if (ok) eh[i] = 1;
    }

    rep(j, w) {
        bool ok = true;
        rep(i, h) {
            if (s[i][j] == '#') ok = false;
        }
        if (ok) ew[j] = 1;
    }

    rep(i, h) {
        if (eh[i] == 1) continue;
        rep(j, w) {
            if (ew[j] == 1) continue;
            cout << s[i][j];
        }
        cout << endl;
    }

    return 0;
}