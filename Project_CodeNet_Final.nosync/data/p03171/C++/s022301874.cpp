#include<bits/stdc++.h>
using namespace std;

#define nax 3009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;
typedef vector<ll> vi;

ll dp[nax][nax];
vi a;

ll f(int ini,int fin,ll s){
	if(ini == fin){
		return s*a[ini];
	}
	if(dp[ini][fin]!=0) return dp[ini][fin];

	if(s==1LL) return dp[ini][fin] = max(f(ini+1,fin,-1LL*s)+s*a[ini],
				f(ini,fin-1,-1LL*s)+s*a[fin]);
	else return dp[ini][fin] = min(f(ini+1,fin,-1LL*s)+s*a[ini],
				f(ini,fin-1,-1LL*s)+s*a[fin]);
}

int main(){
	ll n; cin>>n;
	a.resize(n);
	REP(i,n) cin>>a[i];

	cout<<f(0,n-1,1);

	return 0;
}