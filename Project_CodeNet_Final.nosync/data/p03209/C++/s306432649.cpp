#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

ll pla = 0;
ll ans = 0;
ll n,x;
ll mp[55];
ll pa[55];
bool flag;

void seica(){
	if(!flag){
		cout << ans << endl;
	}
	flag = true;
}

void dfs(int depth){
	pla++;
	if(pla >= x){
		seica();
		return;
	}
	if(depth == 0 || x - pla >= mp[depth-1]){
		pla += mp[depth-1];
		ans += pa[depth-1];
	}
	else{
		dfs(depth - 1);
	}
	if(pla >= x){
		seica();
		return;
	}
	pla++;
	ans++;
	if(pla >= x){
		seica();
		return;
	}
	if(depth == 0 || x - pla >= mp[depth-1]){
		pla += mp[depth-1];
		ans += pa[depth-1];
	}
	else{
		dfs(depth - 1);
	}
	if(pla >= x){
		seica();
		return;
	}
	pla++;
	if(pla >= x){
		seica();
		return;
	}
}

int main(){

	mp[0] = 1;
	pa[0] = 1;
	REP(i,54){
		mp[i+1] = mp[i] * 2 + 3;
		pa[i+1] = pa[i] * 2 + 1;
	}

	cin >> n >> x;
	dfs(n);

	return 0;
}
