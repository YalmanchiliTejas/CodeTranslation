#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
char s[200005];
int f[200005];
int main(){
	// freopen("b.in","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	if(s[1]=='B')
		for(int i=1;i<=m;i++)s[i]=(s[i]=='R'?'B':'R');
	int lst=0,k=n&1?n-2:n-1;
	for(int i=1;i<=m;i++){
		if(s[i]=='B'){
			if(lst!=i-1){
				if(!lst){
					if((i-lst-1)&1)k=min(k,i-lst-1);
					else k=min(k,i-lst-1+1);
				}
				if((i-lst-1)&1)k=min(k,i-lst-1);
			}
			lst=i;
		}
	}
	if(!lst){
		int ans=2;
		f[1]=1;
		for(int i=2;i<=n;i++){
			f[i]=(f[i-1]+f[i-2])%mod;
			if(i!=n)ans=(ans+f[i])%mod;
			else ans=(ans+f[i-1])%mod;
		}
		// puts("ok");
		printf("%d\n",ans);
		return 0;
	}
	k++;
	f[1]=f[3]=1;
	for(int i=5;i<=n;i+=2)f[i]=(2ll*f[i-2]+(i>=k+2?mod-f[i-k-2]:0))%mod;	
	int ans=0;
	for(int i=1;i<=min(n,k);i++)if(i&1)ans=(ans+1ll*f[n-i]*(i+1))%mod;
	printf("%d\n",ans);
	return 0;
}