#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define SF scanf
#define PF printf
#define MAXN 100010
#define MOD 1000000007
using namespace std;
int n;
typedef long long ll;
ll dp[MAXN],h[MAXN];
ll fsp(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1)
			res=res*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return res;
}
int main(){
	SF("%d",&n);
	dp[n+1]=1;
	for(int i=1;i<=n;i++){
		SF("%lld",&h[i]);
		if(h[i]==1){
			h[i]--;
			dp[n+1]=dp[n+1]*2ll%MOD;
		}
	}
	for(int i=1;i<=n;i++)
		if(h[i]>h[i-1]&&h[i]>h[i+1]){
			int h1=max(h[i-1],h[i+1]);
			dp[n+1]=dp[n+1]*fsp(2,h[i]-h1)%MOD;
			h[i]=h1;	
		}
	for(int i=n;i>0;i--){
		//PF("{%d}",i);
		if(h[i])
			dp[i]=dp[i+1]*2ll%MOD;
		else{
			dp[i]=dp[i+1];
			continue;
		} 
	 	ll minh=h[i],q=i;
		for(int j=i;h[j]==h[i];j++)
			if(h[j+1]>h[i]){
				q=j;
				minh++;
			}
		ll res1=0;
		ll end,sumh=0;
		if(h[i]<h[i-1])
			end=h[i];
		else
			end=h[i-1]+1;
		//PF("{%d %d}\n",minh,end);
		for(int j=q+1;minh>end;j++){
			if(h[j]>h[j-1])
				sumh+=h[j]-h[j-1];
			if(h[j]<minh){
				int minh1=max(end,h[j]);
				//PF("{%d %d %d}\n",sumh+h[i]-minh,minh-minh1,-(minh==(h[i]+1)?0:1));
				if(minh==h[i]+1)
					res1+=dp[j]*(fsp(2,sumh+h[i]-minh+q-i+2)+fsp(2,sumh+h[i]-minh+2)*(fsp(2,minh-minh1-1)-1)%MOD)%MOD;
				else
					res1+=dp[j]*(fsp(2,sumh+h[i]-minh+1)*(fsp(2,minh-minh1)-1)%MOD)%MOD;
				res1%=MOD;
				minh=minh1;
			}
		}
		dp[i]+=res1;
		dp[i]%=MOD;
		//PF("{%lld}\n",dp[i]);
	}
	PF("%lld",dp[1]);
} 
