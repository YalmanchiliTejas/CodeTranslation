#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()
const ll MOD = 1000000007;

ll T[100010], S[100010];

int main() {
	for (int i = 0;i < 100010;i++)T[i] = -1, S[i] = 0;
	ll N, X, M, fx, ans = 0;
	cin >> N >> X >> M;
	N--;
	T[X] = N;
	S[X] = X;
	ans += X;
	N--;
	while (N >= 0) {
		X = X * X % M;
		ans += X;
		if (T[X] >= 0) {
			ll tr = T[X] - N;
			ll ntr = N / tr;
			ans += ntr * (ans - S[X]);
			N %= tr;
			N--;
			break;
		}
		T[X] = N;
		S[X] = ans;
		N--;
	}
	while (N >= 0) {
		X = X * X % M;
		ans += X;
		N--;
	}
	cout << ans << endl;
}
