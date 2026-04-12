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

int h, w;
string a[10];

bool solve() {
    bool used[h][w];
    memset(used, false, sizeof(used));
    int i = 0, j = 0;
    while (true) {
        used[i][j] = true;
        if (i == h-1 && j == w-1) break;

        if (i+1 < h && a[i+1][j] == '#') i++;
        else if (j+1 < w && a[i][j+1] == '#') j++;
        else return false;
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!used[i][j] && a[i][j] == '#')
                return false;
        }
    }
    return true;
}

void input() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) cin >> a[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << (solve() ? "Possible" : "Impossible") << endl;
}