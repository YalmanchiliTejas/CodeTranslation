#include <bits/stdc++.h>
#define rep(i, a, n) for(int (i) = (int)(a);(i) < (int)(n);++(i))
#define repe(i, a, n) for(int (i) = (int)(a);(i) <= (int)(n);++(i))
#define repif(i, a, x) for(int (i) = (int)(a);(x);++(i))
#define repr(i, a, n) for(int (i) = ((int)(a)-1);(i) >= (int)(n);--(i))
#define reper(i, a, n) for(int (i) = (int)(a);(i) >= (int)(n);--(i))
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define RNG(x, a, n) &((x)[a]), &((x)[n])
#define ADD(a, b) ((((a+MOD)%MOD)+((b+MOD)%MOD))%MOD)
#define MUL(a, b) ((((a)%MOD)*((b)%MOD))%MOD)
#define CEIL(x) ((int)ceil(((double)x)))
#define POW(x, y) ((int)pow(x, y))
#define UNIQUE(x) (x).erase(unique(ALL((x))), (x).end())
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define yes cout << "yes" << endl;
#define no cout << "no" << endl;
#define fcout cout << fixed << setprecision(10)
#define pb push_back
#define pf push_front
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define EPS (1e-20)
#define INF INT_MAX
#define INFLL LLONG_MAX
#define MOD 1000000007
using llint = long long;
using VI = std::vector<int>;
using PII = std::pair<int, int>;
using SI = std::set<int>;
using MII = std::map<int, int>;
using TIII = std::tuple<int, int, int>;
using MCI = std::map<char, int>;
using VPII = std::vector<PII>;
using namespace std;


int H, W;
char a[110][110];
bool b[110];
bool c[110];
vector<string> ans;


bool judge(int x){
	rep(i, 0, H)
		if(a[i][x] == '#') return false;
	return true;
}


void solve(){
	rep(i, 0, H)
		if(all_of(RNG(a[i], 0, W), [](char c){ return c == '.'; })) b[i] = true;
	rep(i, 0, W)
		if(judge(i)) c[i] = true;
	rep(i, 0, H){
		if(b[i]) continue;
		rep(j, 0, W){
			if(c[j]) continue;
			cout << a[i][j];
		}
		cout << endl;
	}
}


signed main(){
	cin >> H >> W;
	rep(i, 0, H)
		rep(j, 0, W) cin >> a[i][j];

	solve();

	return 0;
}