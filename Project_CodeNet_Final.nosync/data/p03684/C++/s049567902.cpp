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

struct UF
{
	vector<int> par; // 親のインデックスを記憶する配列
	vector<int> sz; // サイズを記憶する。
	vector<int> rank;
	// 初期化
	UF(int n):par(n),sz(n),rank(n){
		for(int i = 0; i < n; i++){
			par[i] = i;sz[i] = 1;rank[i] = 0;
		}
	}
	// 親を求める
	int find(int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}
	// xとyの属する集合を併合
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		if(rank[x] < rank[y]){
			par[x] = y;
			sz[y] += sz[x];
		}
		else{
			par[y] = x;
			sz[x] += sz[y];
			if(rank[x] == rank[y])rank[x]++;
		}
	}
	// xとyが同じ集合ならtrue
	bool same(int x, int y) { return find(x) == find(y); }
	// 素の集合のサイズを求める
	int size(int n){return sz[find(n)];}
};

vector<pair<int,int>> x;
vector<pair<int,int>> y;
vector<pair<int,pair<int,int>>> seica;

int main(){

	int n;cin >> n;
	REP(i,n){
		int a,b;cin >> a >> b;
		x.PB(MP(a,i));
		y.PB(MP(b,i));
	}

	sort(ALL(x));
	sort(ALL(y));

	REP(i,n-1){
		seica.PB(MP(abs(x[i].FI-x[i+1].FI),MP(x[i].SE,x[i+1].SE)));
		seica.PB(MP(abs(y[i].FI-y[i+1].FI),MP(y[i].SE,y[i+1].SE)));
	}

	sort(ALL(seica));

	UF uf(n);
	ll ans = 0;
	REP(i,seica.size()){
		int a = seica[i].SE.FI;
		int b = seica[i].SE.SE;
		int c = seica[i].FI;
		if(!uf.same(a,b)){
			uf.unite(a,b);
			ans += c;
		}
	}

	cout << ans << endl;

	return 0;
}
