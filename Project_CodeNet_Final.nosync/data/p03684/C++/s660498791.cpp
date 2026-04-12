#include <bits/stdc++.h>

using namespace std;

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

typedef long long ll; typedef vector<int> VI; typedef pair<ll,int> pii;
const ll mod = 1e9+7;


struct UF {
	vector<int> par, rank; //root, tree
	UF() {}
	UF(int n){ init(n); }
	void init(int n) {
		par.assign(n+4,0); rank.assign(n+4,0);
		for(int i = 0; i<n; i++) par[i] = i;
	}
	int find(int x){if(par[x] == x) return x; else return par[x] =find(par[x]);}
	void unite(int x, int y) { //unite, (add)
		x = find(x); y = find(y);
		if(x == y) return;
		if(rank[x] < rank[y]){ par[x] = y; }
		else{ par[y] = x; if(rank[x] == rank[y]) rank[x]++;}
	}
	bool same(int x, int y) { return find(x) == find(y); }
};


int main()
{
	
	//cin.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >>n;
	vector<array<int ,3>> xy(n);
	rep(i,n){
		cin >>xy[i][0]>>xy[i][1];
		xy[i][2] =i;
	}
	sort(all(xy));
	auto xy2 =xy;
	sort(all(xy),[](array<int ,3> l, array<int ,3> r){
		return l[1] < r[1];
	}); 
	
	UF ufa(n+4);
	vector<array<int ,3>> cnd;
	
	rep(i,n-1){
		if(xy2[i][0] == xy2[i+1][0]){ ufa.unite(xy2[i][2],xy2[i+1][2]); continue;}
		cnd.push_back(array<int,3>{
			 abs(xy2[i+1][0]-xy2[i][0]),xy2[i][2],xy2[i+1][2]});
		
	}
	rep(i,n-1){
		if(xy[i][0] == xy[i+1][0]){ ufa.unite(xy[i][2],xy[i+1][2]); continue;}
		cnd.push_back(array<int,3>{
			abs(xy[i+1][1]-xy[i][1]),xy[i][2],xy[i+1][2] });
	}	
	
	sort(all(cnd));
	
	//for(auto x :cnd) printf("%d:%d:%d \n ",x[0],x[1],x[2]); puts("");
	ll ans = 0;
	for(auto z: cnd){
	
		if( !ufa.same(z[1],z[2])){
			ans += z[0];
			ufa.unite(z[1],z[2]);
		}
	}
	//rep(i,n) cout << ufa.find(i) <<"  "; puts("");
	cout << ans <<endl;
	return 0;
}
