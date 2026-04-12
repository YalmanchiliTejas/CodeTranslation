#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1000010;
ll n,ans,a[N];
int len,m,x,s,vis[N];
int main(){
	scanf("%lld%d%d",&n,&x,&m);
	a[1]=x;
	for(int i=2;i<=n;i++){
		a[i]=1ll*a[i-1]*a[i-1]%m;
		if(vis[a[i]]){
			len=i-vis[a[i]];
			s=vis[a[i]];
			break;
		}
		vis[a[i]]=i;
	}
	if(!len){
		s=1;
		len=n;
	}
	for(int i=1;i<=s+len-1;i++)
		a[i]+=a[i-1];
	ans+=a[s-1];
	if((n-s+1)%len)
		ans+=(a[s+len-1]-a[s-1])*((n-s+1)/len)+a[(n-s)%len+s]-a[s-1];
	else ans+=(a[s+len-1]-a[s-1])*((n-s+1)/len);
	printf("%lld\n",ans);
	return 0;
}