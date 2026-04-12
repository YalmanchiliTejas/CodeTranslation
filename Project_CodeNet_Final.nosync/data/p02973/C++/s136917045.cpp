#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <sstream>

#define DEBUG 0
#define fi first
#define se second
#define pb push_back
#define fore(i, a, b) for (int i = (a), _b = (b); i < (_b); ++i)
#define fort(i, a, b) for (int i = (a), _b = (b); i <= (_b); ++i)
#define ford(i, a, b) for (int i = (a), _b = (b); i >= (_b); --i)

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int INF = 1e9 + 3;
const int MOD = 1e9 + 7;
const int N = 1e5 + 3;

int n, a[N], b[N], res;

int main() {
    if (DEBUG) {
        freopen("CP.inp", "r", stdin);
        //freopen("CP.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    fort(i, 1, n) cin >> a[i];
    ford(i, n, 1) {
        int len = upper_bound(b + 1, b + 1 + res, a[i]) - b;
        b[len] = a[i];
        res = max(res, len);
    }
    cout << res << '\n';
    return 0;
}
