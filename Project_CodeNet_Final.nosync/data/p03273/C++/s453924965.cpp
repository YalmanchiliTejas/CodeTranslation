#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long

#define rep(i, a) for (int i = 0; (i) < (int) (a); (i)++)
#define reps(i, a, b) for (int i = (int) (a); (i) < (int) (b); (i)++)
#define rrep(i, a) for (int (i) = (int) a-1; (i) >= 0; (i)--)
#define rreps(i, a, b) for (int (i) = (int) (a)-1; (i) >= (int) (b); (i)--)
#define MP(a, b) make_pair((a), (b))
#define PB(a) push_back((a))
#define all(v) (v).begin(), (v).end()
#define PRINT(f) if((f)){cout << (TRUE__) << endl;}else{cout << FALSE__ << endl;}
#define TRUE__ "Yes"
#define FALSE__ "No"
#define PERM(v) next_permutation(all(v))
#define UNIQUE(v) sort(all(v));(v).erase(unique(all(v)), v.end())
#define CIN(type, x) type x;cin >> x

#ifdef LOCAL
	#define lcout(a) cout << a;
	#define lcoutln(a) cout << a << endl;
	#define lcerr(a) cerr << a;
	#define lcerrln(a) cerr << a << endl;
#else
	#define lcout(a) 
	#define lcoutln(a) 
	#define lcerr(a) 
	#define lcerrln(a) 
#endif

#define MOD 1000000007

char m[111][111];
bool fr[111];
bool fc[111];

signed main()
{
	int H, W;
	cin >> H>> W;
	rep(i, H) {
		rep(j, W) {
			cin >> m[i][j];
		}
	}
	rep(i, H) {
		rep(j, W) {
			if (m[i][j] == '#') {
				fr[i] = fc[j] = true;
			}
		}
	}
	rep(i, H) {
		rep(j, W) {
			if (fr[i] && fc[j]) cout << m[i][j];
		}
		if (fr[i]) cout << endl;
	}
}