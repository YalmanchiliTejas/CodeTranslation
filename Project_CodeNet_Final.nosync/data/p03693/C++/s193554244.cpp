#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define rep(i, a) for (int (i) = 0; (i) < (int) (a); (i)++)
#define reps(i, a, b) for (int (i) = (int) (a); (i) < (int) (b); (i)++)
#define rrep(i, a) for (int (i) = (int) a-1; (i) >= 0; (i)--)
#define rreps(i, a, b) for (int (i) = (int) (a)-1; (i) >= (int) (b); (i)--)
#define MP(a, b) make_pair((a), (b))
#define PB(a) push_back((a))
#define all(v) (v).begin(), (v).end()
#define PERM(v) next_permutation(all(v))
#define UNIQUE(v) sort(all(v));(v).erase(unique(all(v)), v.end())
#define CIN(type, x) type x;cin >> x
#define TRUE__ "YES"
#define FALSE__ "NO"
#define PRINT(f) if((f)){cout << (TRUE__) << endl;}else{cout << FALSE__ << endl;}

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

signed main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int r = b * 10 + c;
	PRINT(r % 4 == 0);
}
