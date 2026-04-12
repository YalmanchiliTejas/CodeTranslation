#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,S,a[3005],ans,F[3005][3005],g[3005][3005];

int main(){
	scanf("%d %d",&n,&S);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	F[0][0]=0,g[0][0]=1;
	for(int i=1;i<=n;i++){
		if(a[i]==S) (ans+=1ll*i*(n-i+1)%mod)%=mod;
		else if(a[i]<S) (ans+=1ll*F[i-1][S-a[i]]*(n-i+1)%mod)%=mod;
		for(int j=0;j<=S;j++){
			(F[i][j]+=F[i-1][j])%=mod;
			(g[i][j]+=g[i-1][j])%=mod;
			if(j>=a[i]){
				if(j==a[i]) (F[i][j]+=(F[i-1][j-a[i]]+1ll*i*g[i-1][j-a[i]]%mod)%mod)%=mod;
				else (F[i][j]+=F[i-1][j-a[i]])%=mod;
				(g[i][j]+=g[i-1][j-a[i]])%=mod;
			}
		}
	}
	printf("%d\n",ans);
	
	return 0;
}