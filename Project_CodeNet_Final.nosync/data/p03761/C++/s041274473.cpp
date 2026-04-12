#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define rep(i, a) for (int i = 0; i < (int) (a); i++)
#define reps(i, a, b) for (int i = (int) (a); i < (int) (b); i++)
#define rrep(i, a) for (int i = (int) a-1; i >= 0; i--)
#define rreps(i, a, b) for (int i = (int) (a)-1; i >= (int) (b); i--)
#define MP(a, b) make_pair((a), (b))
#define PB(a) push_back((a))
#define all(v) (v).begin(), (v).end()
#define PRINT(f) if((f)){cout << (TRUE__) << endl;}else{cout << FALSE__ << endl;}
#define TRUE__ "YES"
#define FALSE__ "NO"
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

int cnt[50][1000000];

signed main()
{
	int n;
	cin >> n;
	rep(i, n) {
		CIN(string, s);
		rep(j, s.length()) {
			cnt[i][(unsigned int)s[j]]++;
		}
	}
	for (char c = 'a'; c <= 'z'; c++) {
		int mi = 1e9;
		rep(i, n) mi = min(mi, cnt[i][(unsigned int) c]);
		rep(i, mi) cout << c;
	}
	cout << endl;
}


