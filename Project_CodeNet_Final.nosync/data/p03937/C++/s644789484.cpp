#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define each(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(v) v.begin(), v.end()
#define mset(a, n) memset(a, n, sizeof(a))

typedef long long ll;
typedef vector<int> vi;

const int INF = 1000000000;
const int MOD = 1000000007;
const double eps = 1e-9;

int main(int argc, char *argv[]) {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    int H, W; cin >> H >> W;
    int cnt = 0;
    rep(i, H) {
        string s; cin >> s;
        rep(j, W) if (s[j] == '#') cnt++;
    }
    cout << (cnt == H + W - 1 ? "Possible" : "Impossible") << endl;
    return 0;
}