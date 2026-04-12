#include <cstdio>
#define int long long
typedef long long ll;
const int Maxn=100000;
ll n;
int x,m;
int t;
int a[Maxn+5];
int vis[Maxn+5];
signed main(){
	scanf("%lld%lld%lld",&n,&x,&m);
	a[1]=x;
	vis[x]=1;
	for(int i=2;;i++){
		a[i]=1ll*a[i-1]*a[i-1]%m;
		if(vis[a[i]]){
			t=i;
			break;
		}
		vis[a[i]]=i;
	}
	int sum=0;
	for(int i=1;i<vis[a[t]];i++){
		sum+=a[i];
	}
	n-=vis[a[t]]-1;
	int len=t-vis[a[t]];
	int s=0;
	for(int i=vis[a[t]];i<t;i++){
		s+=a[i];
	}
	sum=(sum+1ll*(n/len)*s);
	int last=n%len;
	for(int i=vis[a[t]];last>0;i++,last--){
		sum+=a[i];
	}
	printf("%lld\n",sum);
	return 0;
}
