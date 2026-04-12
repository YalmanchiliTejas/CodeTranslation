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

int fr[100];
int fc[100];
int H, W;
char m[100][100];

void init()
{
	cin >> H >> W;
	rep(i, H) {
		rep(j, W) {
			char c;
			cin >> c;
			m[i][j] = c;
			if (c == '#') {
				fr[i] = 1;
				fc[j] = 1;
			}
		}
	}
}

void solve()
{
	rep(i, H) {
		if (fr[i] == 0) continue;
		rep(j, W) {
			if (fc[j]) {
				cout << m[i][j];
			}
		}
		cout << endl;
	}
}



