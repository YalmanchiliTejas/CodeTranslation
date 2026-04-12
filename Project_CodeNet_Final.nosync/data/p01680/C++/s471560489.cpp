#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <climits>
#include <numeric>
#include <cstring>
#include <utility>
#include <bitset>
#include <ctime>
#include <cmath>
#include <complex>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<vector<int> > vvint;

typedef long double D;
typedef complex<D> P;
typedef const P &rP;

#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007LL
#define INF 1010101010


LL powmod(LL x, LL y){
	LL a = 1;
	while(y){
		if(y & 1){ a = a * x % MOD; }
		y >>= 1;
		x = x * x % MOD;
	}
	return a;
}


struct UF{
	vector<int> par;

	UF(int n) : par(n + 1){
		for(int i = 1; i <= n; ++i){
			par[i] = i;
		}
	}

	int find(int x){
		return x != par[x] ? par[x] = find(par[x]) : x;
	}

	bool unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y){ return false; }
		if(rand() & 512){ swap(x, y); }
		par[x] = y;
		return true;
	}
};


int main(){
	srand(time(0));
	
	int n, m, a, b;
	while(scanf("%d%d", &n, &m), n){
		UF uf(n);
		for(int i = 0; i < m; ++i){
			scanf("%d%d", &a, &b);
			uf.unite(a, b);
		}

		int c = 0;
		for(int i = 1; i <= n; ++i){
			if(uf.find(i) == i){ ++c; }
		}

		LL ans = 0;

		if(c == n){
			ans = powmod(2, n);
		}
		else{
			ans = (powmod(2, c) + 1) % MOD;
		}
		
		cout << ans << endl;
	}
}