#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;

#define FOR(i, begin, end) for(int i = (begin); i < (end); i++)
#define rep(i, n) FOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define ZP(a, len) cout << setfill('0') << setw(len) << right << a << endl;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

signed main() {
    int h, w;
    cin >> h >> w;

    vs f1 = vs(0);
    rep(i, h) {
        string s;
        cin >> s;
        for (auto c : s) {
            if (c == '#') {
                f1.push_back(s);
                break;
            }
        }
    }

    vs f2 = vs(0);
    rep(i, w) {
        string s = "";
        rep(j, f1.size()) {
            s += f1[j][i];
        }
        if (s.find('#') != s.npos) {
            f2.push_back(s);
        }
    }

    rep(i, f2[0].size()) {
        rep(j, f2.size()) {
            cout << f2[j][i];
        }
        cout << endl;
    }

    return 0;
}