#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<int, P> E;
#define MOD (1000000007ll)
#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	b += MOD;
	a += b;
	a %= MOD;
}

bool g[10][10];
ll dp[334][10],ans=0ll;

int main(void){
	int n,m,i,j,k,a,b;
	fill(dp[0],dp[334],0ll);
	cin >> n >> m;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			g[i][j] = false;
		}
	}
	for(i=0; i<m; ++i){
		cin >> a >> b;
		--a; --b;
		g[a][b] = true;
		g[b][a] = true;
	}
	dp[1][0] = 1ll;
	m = (1<<n);
	for(k=0; k<m; ++k){
		for(i=0; i<n; ++i){
			if(!(k&(1<<i))){
				continue;
			}
			for(j=0; j<n; ++j){
				if(k&(1<<j)){
					continue;
				}
				if(!g[i][j]){
					continue;
				}
				dp[k+(1<<j)][j] += dp[k][i];
			}
		}
	}
	for(i=0; i<n; ++i){
		ans += dp[m-1][i];
	}
	cout << ans << endl;
	return 0;
}
