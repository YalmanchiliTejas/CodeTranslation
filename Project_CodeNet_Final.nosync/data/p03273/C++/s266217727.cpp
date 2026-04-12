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

    vector<bool> eh(h, 0);
    vector<bool> ew(w, 0);
    string s[h];
    rep(i, h) {
        cin >> s[i];
    }

    rep(i, h) {
        rep(j, w) {
            if (s[i][j] == '#') {
                eh[i] = 1;
                ew[j] = 1;
            }
        }
    }


    rep(i, h) {
        if (eh[i] == 0) continue;
        rep(j, w) {
            if (ew[j] == 0) continue;
            cout << s[i][j];
        }
        cout << endl;
    }

    return 0;
}