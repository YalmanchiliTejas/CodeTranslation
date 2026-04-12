#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int mod;
ll n;
ll x;
ll ans[100005];
ll val[100005];
int vis[100005];
int fDate[100005];



int main() {
	scanf("%lld %d %d",&n,&x,&mod);
	ans[1]=x;
	val[1]=x;
	vis[x]=1;
	fDate[x]=1;
	ll l,r;
	bool f=0;
	for(int i=2;i<=n;i++) {
		val[i]=(val[i-1]*val[i-1])%mod;
		ans[i]=ans[i-1]+val[i];
		vis[val[i]]++;
		if(vis[val[i]]==2) {
			//fDate[curF] to i-1 is a complete cycle!
			l=fDate[val[i]];
			r=i-1;
			f=1;
			break;
		}
		fDate[val[i]]=i;
	}
	if(f) {
		ll cycleSum=ans[r]-ans[l-1];
		ll remain=n-r;
		ll trueAns=ans[r];
		trueAns+=remain/(r-l+1)*cycleSum;
		ll leftCnt=remain%(r-l+1);
		int y=0;
		while(leftCnt--) {
			trueAns=trueAns+val[l+y];
			y++;
		}
		printf("%lld",trueAns);
	}else {
		printf("%lld",ans[n]);
	}
	return 0;
}