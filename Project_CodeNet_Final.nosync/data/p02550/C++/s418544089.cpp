#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std; using ll = long long;
using ull = unsigned long long; using P = pair<int, int>;
const int INF = 1e9; const int MOD = 1000000007;
const int dx[] = {-1,0,1,0}; const int dy[] = {0,-1,0,1};
//const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1}; const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
#define PI 3.14159265358979323846264338327950L //setprecision(15)
ll v[100000+1];
ll A[100000+1];
int main() {
	ll N, X, M; cin >> N >> X >> M;
	ll cnt = 1;
	ll tmp = X;
	ll loop = 0;
	ll before_loop = 0; ll after_loop = 0;
	while (1) {
		tmp = tmp % M;
		if (v[tmp] > 0) {
			loop = cnt - v[tmp];
			for (int i = v[tmp]; i < cnt; i++) {
				after_loop += A[i];
			}
			for (int i = 0; i < v[tmp]; i++) {
				before_loop += A[i];
			}
			break;
		}
		v[tmp] = cnt;
		A[cnt] = tmp;
		cnt++;
		tmp *= tmp;
	}
	ll ans;
	if (N < v[tmp]) ans = before_loop;
	else {
		ans = before_loop;
		ans += ( (N - (cnt - loop - 1)) / loop ) * after_loop;
		int tmp3 = (N - (cnt - loop - 1)) % loop;
		for (int i = v[tmp]; i < v[tmp]+tmp3; i++) {
			ans += A[i];
		}
	}
	cout << ans << endl;
}