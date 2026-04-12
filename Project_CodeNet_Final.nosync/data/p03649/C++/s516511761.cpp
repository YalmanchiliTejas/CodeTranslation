#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef vector<int> vi;

const int MOD = 1e9 + 7;
const int INF = INT_MAX / 2;

int main() {
	int N; cin >> N;
	vector<ll> a(N);
	rep(i, N) cin >> a[i];
	ll ans = 0;
	rep(t, 10000) {
		rep(i, N) if (a[i] > N - 1) {
			ll x = a[i] / N;
			a[i] -= x * N;
			rep(j, N) if (j != i) a[j] += x;
			ans += x;
		}
	}
	cout << ans << endl;
}
