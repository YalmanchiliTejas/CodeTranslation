#include <bits/stdc++.h>
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define FSP(x) fixed << setprecision(x)
using namespace std;
using ll = long long;
constexpr ll INF = LLONG_MAX;
constexpr long double PI = acosl(-1);
void Yes() {cout << "Yes\n";}
void No() {cout << "No\n";}
void YES() {cout << "YES\n";}
void NO() {cout << "NO\n";}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//constexpr ll P = 1e9 + 7;
	//constexpr ll P = 998244353;

	ll h, w;
	cin >> h >> w;
	vector<string> a(h);
	vector<bool> badh(h, false), badw(w, false);
	for (ll i = 0; i < h; i++) cin >> a[i];
	for (ll i = 0; i < h; i++) {
		for (ll j = 0; j < w; j++) {
			if (a[i][j] == '#') break;
			if (j == w - 1) badh[i] = true;
		}
	}
	for (ll j = 0; j < w; j++) {
		for (ll i = 0; i < h; i++) {
			if (a[i][j] == '#') break;
			if (i == h - 1) badw[j] = true;
		}
	}
	for (ll i = 0; i < h; i++) {
		if (badh[i]) continue;
		for (ll j = 0; j < w; j++) {
			if (badw[j]) continue;
			cout << a[i][j];
		}cout << endl;
	}
}