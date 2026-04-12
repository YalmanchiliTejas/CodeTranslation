
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

unordered_map<ll, int> used;
ll S[100001];

int main() {
	ll N, X, M;
	cin >> N >> X >> M;

	if (N == 1) {
		cout << X << endl;
		return 0;
	}

	ll i = 2;
	ll A = X;
	S[1] = A;
	while (i<=N) {
		A = A * A % M;
		S[i] = S[i-1] + A;
		if (used[A] > 0) break;
		used[A] = i;
		i++;
	}

	ll ans;
	if (used[A] == N) {
		ans = S[N];
	} else {
		int s = used[A];
		int e = i;
		ll k = S[e] - S[s];
		int l = e - s;
		ll t = (N - s) / l;
		ll r = (N - e) % l;
		ans = S[s] + (S[e] - S[s]) * t + (S[s+r] - S[s]);
		//cout << s << " " << e << " " << t << " " << r << endl; // **** debug ****
	}

	cout << ans << endl;

	//cout << A << " " << used[A] << endl; // **** debug ****

	return 0;
}