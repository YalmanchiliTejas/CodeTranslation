#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define INF 100000000
#define EPS 1e-10
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;

struct UF{
	int par[100000];
	int rank[100000];

	void init(int n){
		rep(i,n){
			par[i] = i;
			rank[i] = 0;
		}
	}

	int find(int x){
		if(par[x] == x) return x;
		else return par[x] = find(par[x]);
	}

	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		
		if(rank[x] < rank[y]) par[x] = y;
		else{
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
		}
	}

	bool same(int x, int y){
		return find(x) == find(y);
	}
};

int n, m;
UF uf;

void solve(){
	uf.init(n);
	rep(i,m){
		int a, b;
		cin >> a >> b;
		a--; b--;
		uf.unite(a,b);
	}
	long long ans = 1;
	bool check = false;
	rep(i,n){
		if(uf.par[i] != i) continue;
		if(uf.rank[i] > 0){
			ans *= 2;
			check = true;
		}
		else ans *= 2;
		ans %= MOD;
	}
	if(check) ans += 1;
	ans %= MOD;
	cout << ans << endl;
}

int main(){
	while(cin>>n >> m ){
		if(n == 0 && m == 0) break;
		solve();
	}
}