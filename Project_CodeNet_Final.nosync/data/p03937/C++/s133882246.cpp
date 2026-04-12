#include <bits/stdc++.h>

#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define mod(x) ((x)%MOD)
#define o(X) (1<<(X))
#define oL(X) (1LL<<(X))
#define LL long long
#define ppt(x) __builtin_popcount(x)
using namespace std;
const int INF=0x3f3f3f3f,N=1e6+5,MOD=1e9+7;
const LL INF_LL=0x3f3f3f3f3f3f3f3fLL;

template<typename T>
inline int getplc(T x,int y) { return (x>>y)&1; }
template<typename T>
T square(T x) {return x*x;}

LL qpow(LL a,LL b=MOD-2,LL _MOD=MOD){
	LL res=1;
	for(;b;b>>=1,a=a*a%_MOD){
		if(b&1)res=res*a%_MOD;
	}
	return res;
}

template <typename T>
T Smax(T x) { return x; }
template<typename T, typename... Args>
T Smax(T a, Args... args) {
	return max(a, Smax(args...));
}
template <typename T>
T Smin(T x) { return x; }
template<typename T, typename... Args>
T Smin(T a, Args... args) {
	return min(a, Smin(args...));
}

template <typename T>
#define errorl(args...) {  \
	string _s = #args;   \
	replace(_s.begin(), _s.end(), ',', ' ');  \
    stringstream _ss(_s);  \
    istream_iterator<string> _it(_ss);  \
    errl(_it, args);  \
}
void errl(istream_iterator<string> it) {}
template<typename T, typename... Args>
void errl(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	errl(++it, args...);
}
#define error(args...) {  \
    string _s = #args;  \
    replace(_s.begin(), _s.end(), ',', ' ');  \
    stringstream _ss(_s);  \
    istream_iterator<string> _it(_ss);  \
    err(_it, args);  \
    cerr<<endl; \
}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << "=" << a << " # ";
	err(++it, args...);
}


char s[10][10];
int suc;
int n, m;

void dfs(int x, int y) {
	if (s[x][y] != '#') return ;
	s[x][y] = '.';
	if (x == n && y == m) {
		suc = 1;
		return ;
	}
	if (s[x][y + 1] == '#') dfs(x, y + 1);
	else if (s[x + 1][y] == '#') dfs(x + 1, y);
}

void Solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i] + 1;
	}
	dfs(1, 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) if (s[i][j] == '#') suc = 0;
	}

	if (suc) cout << "Possible" << '\n';
	else cout << "Impossible" << '\n';
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
//  freopen("o1.txt","w",stdout);
#endif
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	Solve();
	return 0;
}
