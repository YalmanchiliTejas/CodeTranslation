#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define SZ(x) ((int)(x).size())
#define fastin ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
ll ans,n,x,m,a[100010];
int p,last[100010];
int main(){
	cin>>n>>x>>m;
	a[++p]=x;
	last[x]=1;
	int zero=0;
	while(1){
		ll tmp=a[p]*a[p]%m;
		if(last[tmp]||tmp==0){
			if(!tmp)	zero=1;
			break;
		}
		++p;
		last[tmp]=p;
		a[p]=tmp;
	}
	if(n<=p){
		rep(i,1,n)	ans+=a[i];
		printf("%lld\n",ans);
	}
	else{
		if(zero){
			rep(i,1,p)	ans+=a[i];
			printf("%lld\n",ans);
		}
		else{
			ll bgn=a[p]*a[p]%m;
			ll sum=0;
			rep(i,last[bgn],p)	sum+=a[i];
			ll len=p-last[bgn]+1;
			rep(i,1,p)	ans+=a[i];
			n-=p;
			ans=ans+(n/len*sum);
			n%=len;
			rep(i,last[bgn],last[bgn]+n-1)	ans+=a[i];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
