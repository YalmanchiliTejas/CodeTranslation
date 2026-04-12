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
const int N = 3003;

int n, a[N];
LL f[N][N];

void input() {
	cin >> n;
	fort(i, 1, n) cin >> a[i];
}

void solve() {
	fort(i, 1, n) f[i][i] = a[i];
	fort(l, 2, n) fort(i, 1, n - l + 1) {
		int j = i + l - 1;
		f[i][j] = max(a[i] - f[i + 1][j], a[j] - f[i][j - 1]);
	}	
	cout << f[1][n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	solve();
    return 0;
}
