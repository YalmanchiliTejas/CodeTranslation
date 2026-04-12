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
ll a[55];

bool check(ll k) {
    ll m = 0;
    for (int i = 0; i < n; i++) {
        m += max(0LL, (a[i] + k + 1) / (n + 1));
    }
    return m <= k;
}

ll solve() {
    ll lb = -1, ub = 1e18;
    while (ub - lb > 1) {
        ll mid = (ub + lb) / 2;
        bool f = false;
        for (ll i = max(lb, mid-25); i <= min(ub-1, mid+25); i++) {
            if (check(i)) {
                ub = i;
                f = true;
                break;
            }
        }
        if (!f)
            lb = mid;
        /*
        if (check(mid)) {
            ub = mid;
        } else {
            lb = mid;
        }
        */
    }
    return ub;
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
