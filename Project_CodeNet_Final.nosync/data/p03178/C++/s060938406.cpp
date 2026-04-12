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

string k;
int d;

ll dp[10010][11][101];

ll solve() {
    dp[0][0][0] = 1;
    int len = (int)k.size();
    for (int i = 1; i <= len; i++) {
        for (int v = 0; v < 10; v++) {
            for (int r = 0; r < d; r++) {
                for (int u = 0; u < 10; u++) {
                    dp[i][v][r] += dp[i-1][u][(r-v%d+d)%d];
                    dp[i][v][r] %= mod;
                }
            }
        }
    }
    
    ll res = 0;
    for (int j = 0; j < (int)(k[0]-'0'); j++) {
        res += dp[len][j][0];
        res %= mod;
    }
    int sum = (int)(k[0]-'0') % d;
    for (int i = len-1; i > 0; i--) {
        for (int j = 0; j < (int)(k[len-i]-'0'); j++) {
            res += dp[i][j][(d-sum)%d];
            res %= mod;
        }
        sum += (int)(k[len-i]-'0');
        sum %= d;
    }
    if (sum == 0) {
        res += 1;
        res %= mod;
    }
    res += mod-1;
    res %= mod;
    return res;
}

void input() {
    cin >> k >> d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
