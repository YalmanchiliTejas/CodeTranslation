#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
typedef unsigned long long ull;
const int N=1000005;
int m,a[N];
ll s[N],n;
map<int,int> mp;
int main(){
	scanf("%lld%d%d",&n,&a[1],&m);rll ans=a[1];s[1]=a[1],mp[a[1]]=1;
	for(it i=2;i<=n;++i){
		a[i]=(0ll+a[i-1])*a[i-1]%m;
		if(mp[a[i]]){
			ans+=(s[i-1]-s[mp[a[i]]-1])*((n-i+1)/(i-mp[a[i]]))+s[mp[a[i]]+(n-i+1)%(i-mp[a[i]])-1]-s[mp[a[i]]-1];
			//printf("%d %d %lld %lld\n",(n-i+1)/(i-mp[a[i]]),(n-i+1)%(i-mp[a[i]]),s[i-1]-s[mp[a[i]]-1],s[mp[a[i]]+(n-i+1)%(i-mp[a[i]])-1]-s[mp[a[i]]-1]);
			break;
		}
		ans+=a[i],mp[a[i]]=i,s[i]=s[i-1]+a[i];
	}
	printf("%lld",ans);
	return 0;
}
