#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
const int INF = 1e9;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	ll ans = 0;

	cin >> N;
	vector<ll> A(N);
	rep(i, N) cin >> A[i];
	deque<ll> dq;

	rep(i, N) {
		auto itr = lower_bound(dq.rbegin(), dq.rend(), A[i]);
		if (itr == dq.rbegin()) {
			dq.push_back(A[i]);
		}
		else {
			itr--;
			*itr = A[i];
		}
	}

	ans = dq.size();
	cout << ans << "\n";

	return 0;
}
