#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
int a,b,c,d;
ll dp[1005][1005];
ll comb[1005][1005];

ll extgcd(ll a,ll b,ll& x,ll& y){
	ll d=a;
	if(b!=0){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else{
		x=1;
		y=0;
	}
	return d;
}

ll mod_inverse(ll a,ll m){
	ll x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}

int main(void){
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	for(int i=0;i<=n;i++){
		comb[i][i]=1;
		comb[i][0]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%MOD;
		}
	}
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		for(int k=0;k<=n;k++){
			dp[i+1][k]+=dp[i][k];
			dp[i+1][k]%=MOD;
			ll cal=1;
			ll v=0;
			for(int j=(i+1);j<=n-k;j+=(i+1)){
				cal=cal*comb[n-k-v*(i+1)][i+1]%MOD;
				//printf("%lld %lld %d\n",cal,n-k-v*(i+1),i+1);
				cal=cal*mod_inverse(v+1,MOD)%MOD;
				//printf("%lld %lld %d\n",cal,n-k-v*(i+1),i+1);
				v++;
				if(i+1<a || i+1>b)continue;
				if(v<c || v>d)continue;
				if(j+k<=n){
					dp[i+1][j+k]+=dp[i][k]*cal%MOD;
					dp[i+1][j+k]%=MOD;
					if(dp[i+1][j+k]>0){
						//printf("dp %d %d %lld\n",i+1,j+k,dp[i+1][j+k]);
					}
				}
			}
		}
	}
	printf("%lld\n",dp[n][n]);
	return 0;
}
