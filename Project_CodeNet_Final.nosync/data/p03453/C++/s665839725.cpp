#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please


#define PT pair<ll, int>
int N, M, S, T;
vector<PT> E[100001];
ll D[100001];
ll dp1[100001], dp2[100001];
ll mod = 1e9 + 7;

ll search1(int A) {
	if (dp1[A] != -1) return dp1[A];
	ll ret = 0;
	for (auto p : E[A]) {
		if (D[p.second] == D[A] + p.first) {
			ret = (ret + search1(p.second)) % mod;
		}
	}
	dp1[A] = ret;
	return ret;
}

ll search2(int A) {
	if (dp2[A] != -1) return dp2[A];
	ll ret = 0;
	for (auto p : E[A]) {
		if (D[p.second] == D[A] - p.first) {
			ret = (ret + search2(p.second)) % mod;
		}
	}
	dp2[A] = ret;
	return ret;
}

ll hanbun;
ll kotae = 0;
void calc(int A) {
	if (D[A] == hanbun) {
		ll kari = search1(A) * search2(A) % mod;
		kotae = (kotae + kari * kari) % mod;
	}
	else if(D[A] < hanbun) {
		for (auto p : E[A]) {
			if (D[A] + p.first > hanbun && D[A] + p.first == D[p.second]) {
				ll kari = search1(p.second) * search2(A) % mod;
				kotae = (kotae + kari * kari) % mod;
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	cin >> N >> M >> S >> T;

	rep(i, M) {
		int u, v, d;
		cin >> u >> v >> d;
		E[u].pb(mp(2 * d, v));
		E[v].pb(mp(2 * d, u));
	}

	rep1(i, N) D[i] = 1e18;
	D[S] = 0;

	priority_queue<PT, vector<PT>, greater<PT>> que;
	que.push(mp(0, S));
	while (que.size()) {
		PT p = que.top();
		que.pop();
		int i = p.second;
		if (D[i] != p.first) continue;
		for (PT p2 : E[i]) {
			int j = p2.second;
			ll d = D[i] + p2.first;
			if (D[j] > d) {
				D[j] = d;
				que.push(mp(d, j));
			}
		}
	}
	
	hanbun = D[T] / 2;

	rep1(i, N) dp1[i] = -1;
	dp1[T] = 1;
	rep1(i, N) dp2[i] = -1;
	dp2[S] = 1;
	rep1(i, N) calc(i);

	co((search1(S) * search1(S) % mod - kotae + mod) % mod);

	Would you please return 0;
}
