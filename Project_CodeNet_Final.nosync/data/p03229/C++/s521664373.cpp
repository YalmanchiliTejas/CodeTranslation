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
#define RS resize
#define CINV(v, N) do {\
	v.RS(N);\
	rep(i, N) cin >> v[i];\
} while (0);
#define RCINV(v, N) do {\
	v.RS(N);\
	rrep(i, N) cin >> v[i];\
} while (0);

#define MOD 1000000007

ll init();
void solve();

signed main()
{
	cout << init() << endl;
	solve();
}

ll init()
{
	int N;
	cin >> N;
	vector<ll> a(N);
	vector<ll> k1(N);
	vector<ll> k2(N);
	rep(i, N) cin >> a[i];
	sort(all(a));
	if (N == 2) return abs(a[0] - a[1]);
	if (N % 2) {
		k1[0] = k1[1] = 1;
		k2[0] = k2[1] = -1;
	} else {
		k1[0] = k2[1] = 1;
		k1[1] = k2[0] = -1;
	}
	int f = -1;
	reps(i, 2, N) {
		k1[i] = f * 2;
		k2[i] = -f * 2;
		f = -f;
	}
	sort(all(k1));
	sort(all(k2));
	ll res1 = 0;
	ll res2 = 0;
	rep(i, N) {
		res1 += k1[i] * a[i];
		res2 += k2[i] * a[i];
	}
	return max(res1, res2);
}

void solve()
{
}


