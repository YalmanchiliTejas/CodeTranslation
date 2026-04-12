#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <tuple>
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef complex<double> comp;
typedef vector< vector<ld> > matrix;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

ll n;
ll a[200100];

ll dp[200100][3];

ll solve() {
    dp[0][0] = 0;
    dp[0][1] = -1e18;
    dp[0][2] = -1e18;
    dp[1][0] = 0;
    dp[1][1] = a[0];
    dp[1][2] = -1e18;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            int k = i / 2 + (j < 2 ? j : -1);
            int idx = -1;
            for (int p = 0; p < 3; p++) {
                if ((i-1) / 2 + (p < 2 ? p : -1) == k) {
                    idx = p;
                    break;
                }
            }
            if (idx >= 0) {
                dp[i][j] = dp[i-1][idx];
            } else {
                dp[i][j] = -1e18;
            }

            idx = -1;
            for (int p = 0; p < 3; p++) {
                if ((i-2) / 2 + (p < 2 ? p : -1) == k-1) {
                    idx = p;
                    break;
                }
            }
            if (idx >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-2][idx]+a[i-1]);
            } else {
                dp[i][j] = -1e18;
            }
        }
    }
    
    return dp[n][0];
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
