#include <bits/stdc++.h>
#define FOR(i,N) for(auto i=0; i<N; ++i)
#define ALL(x) x.begin(), x.end()
using namespace std;
using ll=long long;
signed main()
{
	ll N,M; cin >> N >> M;
	vector< vector< ll > > children(N+1);
	FOR(i,M) {
		ll a, b;		cin >> a >> b;
		children[a].push_back(b);
		children[b].push_back(a);
	}
	vector<ll> PERM(N); iota(ALL(PERM), 1);
	ll ans = 0;
	do {
		bool ok = true;
		if (PERM[0] != 1) continue;
		FOR(i, N-1) { auto v = PERM[i]; auto nextv = PERM[i+1];
			if( find(ALL(children[v]),  nextv) == children[v].end()) {
				ok = false; break;
			}
		}
		if (ok) ans += 1;
	} while (next_permutation(ALL(PERM))) ;
	
	cout << ans << endl;
	return 0;
}