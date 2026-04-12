#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, a) for (int i = 0; (i) < (int) (a); (i)++)
#define reps(i, a, b) for (int i = (int) (a); (i) < (int) (b); (i)++)
#define rrep(i, a) for (int i = (int) a-1; (i) >= 0; (i)--)
#define rreps(i, a, b) for (int i = (int) (a)-1; (i) >= (int) (b); (i)--)
#define MP(a, b) make_pair((a), (b))
#define PB(a) push_back((a))
#define all(v) (v).begin(), (v).end()
#define PERM(v) next_permutation(all(v))
#define UNIQUE(v) sort(all(v));(v).erase(unique(all(v)), v.end())
#define CIN(type, x) type x;cin >> x
#define TRUE__  "Yes"
#define FALSE__ "No"
#define PRINT(f) if((f)){cout << (TRUE__) << endl;}else{cout << FALSE__ << endl;}
#define RS(N) resize(N)
#define CINV(v, N) do {\
	v.RS(N);\
	rep(i, N) cin >> v[i];\
} while (0);
#define RCINV(v, N) do {\
	v.RS(N);\
	rrep(i, N) cin >> v[i];\
} while (0);

#define MOD 1000000007

void init();
void solve();

signed main()
{
	init();
	solve();
}

vector<ll> P, A;
ll N, X;

ll saiki(int lev, ll pos = -1)
{
	ll res;
	if (lev < 0) res = 0;
	else if (pos < 0) {
		res = P[lev];
	}
	else if (lev == 0 && pos == 1) res = 1;
	else if (lev == 0) res = 0;
	else if (pos == 1) res = 0;
	else {
		ll S = A[lev-1] + 2;
		if (pos < S) {
			res = saiki(lev-1, pos-1);
		}
		else if (pos == S) {
			res = saiki(lev-1, pos-2) + 1LL;
		}
		else {
			pos = min(pos, A[lev]-1);
			res = 1LL + saiki(lev-1) + saiki(lev-1, pos - A[lev-1] - 2);
		}
	}
	return res;
}


void init()
{
	cin >> N >> X;
	A.RS(N+1);
	P.RS(N+1);
	A[0] = P[0] = 1;
	rep(i, N) {
		A[i+1] = A[i] * 2 + 3;
		P[i+1] = P[i] * 2 + 1;
	}
}

void solve()
{
	cout << saiki(N, X) << endl;
}
