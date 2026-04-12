#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <queue>
#include <deque>
#include <fstream>
#include <bitset>
#include <cassert>
using namespace std;
 
#define int long long
#define double long double
#define mp make_pair
#define all(a) a.begin(), a.end()
#define pb push_back
#define debug(x) cerr << #x << ": " << x << '\n';
#define ppoint(p) cout << #p << ' ' << p.x << ' ' << p.y << '\n';
#define fi first
#define se second
#define FOR(i, n) for (int i = 0; i < n; ++i)
//typedef long long ll;
typedef pair<int, int> pii;
 
template<typename T1, typename T2> inline bool chkmin(T1 &x, T2 y) { return y < x ? (x = y, true) : false; };
template<typename T1, typename T2> inline bool chkmax(T1 &x, T2 y) { return y > x ? (x = y, true) : false; };
 
void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

const int N = 201;
int a[N];
int c[N][N];
int p[N];

int get(int n, int k) {
	if (k < 0) return 0;
	if (k > n) return 0;
	return c[n][k] * p[k];
}

signed main() {
	fast();
	string s;
	cin >> s;
	int k;
	cin >> k;
	int kk = k;
	int ans = 0;
	for (int i = 0; i < N; i++) c[i][0] = c[i][i] = 1;
	p[0] = 1;
	for (int i = 1; i < N; i++) p[i] = p[i - 1] * 9;
	for (int i = 2; i < N; i++) {
		for (int j = 1; j < i; j++) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
	//debug(get(1, 1));
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') continue;
		if (s[i] > '1') {
			ans += (s[i] - '1') * get(s.size() - i - 1, kk - 1);
		}
		if (s[i] > '0') ans += get(s.size() - i - 1, kk);
		kk--;
	}
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) if (s[i] > '0') cnt++;
	if (cnt == k) ans++;
	cout << ans;
	return 0;
}