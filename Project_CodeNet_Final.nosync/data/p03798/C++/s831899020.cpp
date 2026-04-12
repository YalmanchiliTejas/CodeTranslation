#include <bits/stdc++.h>
#include <cstdio>
 
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
void init();
void solve();

signed main()
{
    init();
    solve();
}

int N;
vector<bool> v;

void init()
{
	cin >> N;
	string s;
	cin >> s;
	rep(i, N) {
		v.PB(s[i] != 'o');
	}
}

void print(vector<bool>& res)
{
	for (auto x : res) {
		if (x) cout << 'W';
		else cout << 'S';
	}
	cout << endl;
}

bool ch(vector<bool>& res, int pos)
{
	int a = pos-1;
	int b = pos+1;
	if (pos == 0) {
		a = N-1;
	}
	if (pos == N-1) {
		b = 0;
	}
	return v[pos] != ((res[a] == res[b]) ^ res[pos]);
}

bool calc(vector<bool>& res)
{
	reps(i, 2, N) {
		res[i] = res[i-2] ^ v[i-1] ^ res[i-1];
	}
	rep(i, N) {
		if (!ch(res, i)) return false;
	}
	return true;
}


void solve()
{
	vector<bool> res(N);
	rep(i, 2) {
		rep(j, 2) {
			res[0] = i == 0;
			res[1] = j == 0;
			if (calc(res)) {
				print(res);
				return;
			}
		}
	}
	cout << -1 << endl;
}

