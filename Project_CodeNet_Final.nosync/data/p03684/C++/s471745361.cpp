#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<functional>
#include<queue>
#include <iomanip>
#include<map>
#include<limits>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<utility>
#include<complex>
#include<cstdlib>
#include<set>
#include<cctype>

#define DBG cerr << '!' << endl;
#define REP(i,n) for(int (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(int (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(int (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int i = 0;i < (n);i++)cerr << v[i] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(10)

using namespace std;

typedef long long ll;
typedef vector<int> iv;
typedef vector<iv> iiv;
typedef vector<string> sv;


struct UF
{
	vector<int> par; // 親
	// 初期化
	UF(int n):par(n) {
		for(int i = 0; i < n; i++){
			par[i] = i;
		}
	}
	// 木の根を求める
	int find(int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}
	// xとyの属する集合を併合
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		// 木の高さが高い方を代表ノードにする
		par[x] = y;
	}
	// xとyが同じ集合ならtrue
	bool same(int x, int y) { return find(x) == find(y); }
};

vector<pair<int,pair<int,int> > > v;

int kruskal(int n)
{
	sort(ALL(v));
	UF uf(n);
	
	int ret = 0;
	
	REP(i,v.size())
	{
		pair<int,pair<int,int> > e = v[i];
		if(!uf.same(e.SE.FI,e.SE.SE))
		{
			uf.unite(e.SE.FI,e.SE.SE);
			ret += e.FI;
		}
	}
	return ret;
}
	

int main()
{
	int n;
	cin >> n;
	
	
	vector<pair<int,int> > dx;
	vector<pair<int,int> > dy;
	
	REP(i,n)
	{
		int x,y;
		cin >> x >> y;
		dx.PB(MP(x,i));
		dy.PB(MP(y,i));
	}
	
	sort(ALL(dx));
	sort(ALL(dy));
	
	REP(i,n-1)
	{
		v.PB(MP(abs(dx[i].FI - dx[i+1].FI),MP(dx[i].SE,dx[i+1].SE)));
		v.PB(MP(abs(dy[i].FI - dy[i+1].FI),MP(dy[i].SE,dy[i+1].SE)));
	}
	
	cout << kruskal(n) << endl;
	
	
	return 0;
}