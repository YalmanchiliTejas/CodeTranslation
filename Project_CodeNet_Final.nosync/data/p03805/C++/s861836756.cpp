#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
const ll INF=1e9+7;
const ll N = 9;
ll n,m,a,b,ans=0;
bool e[N][N];
bool did[N];

bool allgo(){
	bool ok=true;
	FOR(i,1,n+1){
		if(did[i]==false)ok=false;
	}
	return ok;
}

void dfs(ll s,ll f){
	did[s]=true;
	FOR(i,1,n+1){
		if(did[i]==false&&e[s][i]==true){
			did[i]=true;
			if(allgo()&&i==f){
				ans++;
			}
			dfs(i,f);
		}
	}
	did[s]=false;
}

int main(){
	cin>>n>>m;
	FOR(i,0,m){
		cin>>a>>b;
		e[a][b]=e[b][a]=true;
	}
	FOR(i,2,n+1){
		FOR(j,0,n+1)did[j]=false;
		dfs(1,i);
	}
	cout<<ans<<endl;
	return 0;
}