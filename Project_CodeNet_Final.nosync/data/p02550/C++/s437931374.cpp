#pragma GCC optimize ("O2")
#pragma GCC target ("avx2")
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	ll N, X, M;
	cin >> N >> X >> M;

	ll x = X % M;

	vector<ll> V;
	V.pb(x);
	set<ll> ST;
	ST.insert(x);
	int hajimari = 0;
	while (1) {
		ll tmp = V.back();
		tmp = tmp * tmp % M;
		if (ST.count(tmp)) {
			int k = 0;
			for (; k < V.size(); k++) {
				if (V[k] == tmp) {
					break;
				}
			}
			hajimari = k;
			break;
		}
		V.pb(tmp);
		ST.insert(tmp);
	}

	int K = V.size() - hajimari;
	ll kei = 0;
	for (int i = hajimari; i < V.size(); i++) kei += V[i];

	if (N <= hajimari) {
		ll kotae = X - x;
		rep(i, N) {
			kotae += V[i];
		}
		co(kotae);
		return 0;
	}

	ll kotae = X - x;
	rep(i, hajimari) {
		kotae += V[i];
	}
	N -= hajimari;

	ll shou = N / K;
	int amari = N % K;

	kotae += shou * kei;
	for (int i = hajimari; i < hajimari + amari; i++) kotae += V[i];
	
	co(kotae);

	Would you please return 0;
}