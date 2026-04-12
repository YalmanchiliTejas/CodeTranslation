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
#define TRUE__  "YES"
#define FALSE__ "NO"
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

void init();
void solve();

signed main()
{
	init();
	solve();
}

int N;
vector<int> A;
vector<vector<int> > k;

void init()
{
	cin >> N;
	CINV(A, N);
	sort(all(A));
	k.resize(2);
}

void mk(int x, int a)
{
	rep(i, N) {
		k[a].PB(x);
		x = -x;
	}
	k[a].back() /= 2;
	k[a].front() /= 2;
	sort(all(k[a]));
}

ll culc(int a)
{
	ll res = 0;
	rep(i, N) {
		res += k[a][i] * A[i];
	}
	return res;
}


void solve()
{
	mk(2, 0);
	mk(-2, 1);
	cout << max(culc(0), culc(1)) << endl;
}


