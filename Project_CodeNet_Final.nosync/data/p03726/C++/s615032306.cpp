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
typedef pair<ll, int> P;
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
int a[100100], b[100100];

vector<int> G[100100];

int calc(int v, int prev) {
    int cnt = 0;
    for (int u : G[v]) {
        if (u == prev) continue;
        int ret = calc(u, v);
        if (ret < 0)
            return -1;
        if (ret == 0)
            cnt++;
    }
    if (cnt == 0) return 0;
    if (cnt == 1) return 1;
    return -1;
}

bool solve() {
    for (int i = 0; i < n-1; i++) {
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    return calc(0, -1) != 1;
}

void input() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << (solve()?"First":"Second") << endl;
}
