#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void init();
void solve();

#define rep(i, a) for (int i = 0; i < (int) (a); i++)
#define reps(i, a, b) for (int i = (int) (a); i < (int) (b); i++)
#define rrep(i, a) for (int i = (int) a-1; i >= 0; i--)
#define rreps(i, a, b) for (int i = (int) (a)-1; i >= (int) (b); i--)
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

string s;

signed main()
{
	init();
	solve();
}

ll N, M;
bool con[8][8];

void init()
{
	cin >> N >> M;
	rep(i, M) {
		CIN(int, a);
		CIN(int, b);
		a--;b--;
		con[a][b] = con[b][a] = true;
	}
}

bool hou[8];

int saiki(int pos = 0, int cnt = 1)
{
	if (hou[pos]) return 0;
	if (cnt == N) return 1;
	hou[pos] = true;
	int res = 0;
	rep(i, N) {
		if (con[pos][i]) res += saiki(i, cnt+1);
	}
	hou[pos] = false;
	return res;
}

void solve()
{
	cout << saiki() << endl;
}
