#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

int main() {
	
	int n;
	cin >> n;
	vi a(n);
	vi sum(n + 1);
	ll ans = 0;
	rep(i, n) {
		cin >> a[i];
		sum[i + 1] = sum[i] + a[i];sum[i + 1] %= MOD;
		ll p = (ll)a[i] * sum[i];p %= MOD;
		ans += p;ans %= MOD;
	}

	cout << ans << endl;

}