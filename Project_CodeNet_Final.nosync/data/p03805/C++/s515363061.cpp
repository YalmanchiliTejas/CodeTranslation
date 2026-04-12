#include "bits/stdc++.h"
using namespace std;
#define repi(i,a,b) for(int i=(a), i##_len=(b); i<i##_len; ++i)
#define rep(i,n) repi(i,0,n)
#define repi_(i,a,b) for(int i=(a), i##_len=(b); i<=i##_len; ++i)
#define rep_(i,n) repi_(i,0,n)
#define all(x) (x).begin(),(x).end()
#define vsort(v) sort((v).begin(), (v).end())
#define gsort(v) tsort(v); reverse((v).begin(), (v).end())
#define vrev(v) reverse((v).begin(), (v).end())
#define siz(v) ((int)(v).size())
#define ers(v, n) (v).erase((v).begin() + n)
#define cnt(v, n) count(all(v), n)
#define vmin(v) *min_element(v.begin(), v.end())
#define vmax(v) *max_element(v.begin(), v.end())
#define el "\n"
#define co(x) cout<<(x)<<el
#define coc(c, a, b) if(c)co((a));else co((b))
#define cosp(x) cout<<(x)<<' '
#define YES(c) coc(c,"YES", "NO")
#define Yes(c) coc(c,"Yes", "No")
#define yes(c) coc(c,"yes", "no")
#define POSSIBLE(c) coc(c, "POSSIBLE", "IMPOSSIBLE")
#define Possible(c) coc(c, "Possible", "Impossible")
#define possible(c) coc(c, "possible", "impossible")
#define inf INT_MAX
#ifdef tqktmp_2
#define gc() getchar(); getchar()
#else
#define gc() 1
#endif
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))


typedef long long lint;

lint dx[8] = { 0,1,1,1,0,-1,-1,-1 },
dy[8] = { 1,1,0,-1,-1,-1,0,1 };

template<class T>inline bool maxi(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>inline bool mini(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }


lint n, m, ina, inb;
vector<lint> a, b;
vector<bool> flag;
vector<bool> eflag;
bool allvisited;

lint dfs(lint now, lint len) {//nowから先に何個それがあるか
	allvisited = 1;
	rep(i, n) {
		if (!flag[i]) {
			allvisited = 0;
			break;
		}
	}
	if (allvisited)return 1;

	lint ret = 0;
	rep(i, m) {
		if (a[i] == now && !eflag[i] && !flag[b[i]-1]) {
			eflag[i] = 1;
			flag[b[i]-1] = 1;
			ret += dfs(b[i], len + 1);
			eflag[i] = 0;
			flag[b[i]-1] = 0;
		}
		else if (b[i] == now && !eflag[i] && !flag[a[i]-1]) {
			eflag[i] = 1;
			flag[a[i]-1] = 1;
			ret += dfs(a[i], len + 1);
			eflag[i] = 0;
			flag[a[i]-1] = 0;
		}
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	flag.push_back(1);
	rep(i,n-1)flag.push_back(0);
	rep(i, m) {
		cin >> ina >> inb;
		a.push_back(ina);
		b.push_back(inb);
		eflag.push_back(0);
	}

	co(dfs(1, 0));

	gc();
}