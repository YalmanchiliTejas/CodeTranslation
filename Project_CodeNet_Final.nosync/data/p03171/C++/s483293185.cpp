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
const int inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

int n;
ll a[3010];

ll dp[3010][3010];

ll calc(int l, int r, ll rem) {
    if (l > r) return 0;
    if (dp[l][r] < 0) {
        ll L = rem - calc(l+1, r, rem-a[l]);
        ll R = rem - calc(l, r-1, rem-a[r]);
        dp[l][r] = max(L, R);
    }
    return dp[l][r];
}

ll solve() {
    ll sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    memset(dp, -1, sizeof(dp));
    ll X = calc(0, n-1, sum);
    ll Y = sum - X;
    return X - Y;
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
