#include <bits/stdc++.h>

#define fs first
#define sc second
#define mp make_pair
#define pb emplace_back
#define sz(s) ((int) s.size ())
#define all(s) s.begin (), s.end ()

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef unsigned long long ull;

const ll linf = (ll) 1e18;

const int pw = 997;
const int N = 19;
const int inf = (int) 1e9;
const int mod = (int) 1e9 + 7;

const double eps = 1e-10;
const double pi = 3.1415926535897932384626433832795;

int p[N];

bool g[N][N];

inline void prepare () {

}
inline void solve () {
        int n, m; cin >> n >> m;
        for (int i = 0; i < m; i++) {
                int a, b; cin >> a >> b; --a, --b; g[a][b] = g[b][a] = 1;
        }
        for (int i = 0; i < n; i++) {
                p[i] = i;
        }
        int ans = 0;
        do {
                bool good = 1;
                for (int i = 0; i < n - 1; i++) {
                        if (!g[p[i]][p[i + 1]]) {
                                good = 0;
                                break;
                        }
                }
                ans += good;
        }while (next_permutation (p + 1, p + n));
        cout << ans;
}
int main () {
        #ifdef FSTREAM
                #define name ""
                freopen (name".in", "r", stdin);
                freopen (name".out", "w", stdout);
        #endif // FSTREAM
        int tests = 1;
        prepare ();
	while (tests--) {
                solve ();
        }
}
