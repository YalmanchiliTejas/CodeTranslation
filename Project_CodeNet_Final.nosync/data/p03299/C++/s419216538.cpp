#include <bits/stdc++.h>
#define SIZE 205
#define INF 1000000005
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
vector <int> vx;
int H[SIZE];
ll dp[2][SIZE];
ll all[SIZE];
ll mpow(ll m,ll t){
	if(t==0) return 1LL;
	ll ret=mpow(m,t/2);
	ret=ret*ret%MOD;
	if(t%2==1) ret=ret*m%MOD;
	return ret;
}
int main(){
	int n;
	scanf("%d",&n);
	vx.push_back(INF);
	vx.push_back(1);
	for(int i=0;i<n;i++){
		scanf("%d",&H[i]);
		vx.push_back(H[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	int pos=0;
	for(int i=0;i+1<vx.size();i++){
		int low=vx[i]+1,up=vx[i+1];
		up=min(up,H[0]);
		if(low>up) dp[pos][i]=0;
		else{
			dp[pos][i]=2LL*(mpow(2,up-low+1)-1LL)%MOD*mpow(2,H[0]-up)%MOD;
		}
	}
	all[0]=2LL;
	for(int i=1;i<n;i++){
		pos^=1;
		memset(dp[pos],0,sizeof(dp[pos]));
		int t=lower_bound(vx.begin(),vx.end(),H[i])-vx.begin();
		for(int j=0;j+1<vx.size();j++){
			if(dp[pos^1][j]==0) continue;
			if(j+1<=t){
				ll vl=dp[pos^1][j];
				if(H[i-1]<H[i]) vl=vl*mpow(2,H[i]-H[i-1])%MOD;
				dp[pos][j]+=vl;
				if(dp[pos][j]>=MOD) dp[pos][j]-=MOD;
			}else{
				all[i]+=dp[pos^1][j]*2LL%MOD;
				if(all[i]>=MOD) all[i]-=MOD;
			}
		}
		if(all[i-1]!=0){
			for(int j=0;j+1<vx.size();j++){
				int low=vx[j]+1,up=vx[j+1];
				low=max(low,H[i-1]+1);
				up=min(up,H[i]);
				if(low<=up){
					dp[pos][j]+=all[i-1]*2LL%MOD*(mpow(2,up-low+1)-1LL)%MOD*mpow(2,H[i]-up)%MOD;
					if(dp[pos][j]>=MOD) dp[pos][j]-=MOD;
				}
			}
			all[i]+=all[i-1]*2LL%MOD;
			if(all[i]>=MOD) all[i]-=MOD;
		}
	}
	ll ret=all[n-1];
	for(int i=0;i+1<vx.size();i++){
		ret+=dp[pos][i];
		if(ret>=MOD) ret-=MOD;
	}
	printf("%lld\n",ret);
	return 0;
}