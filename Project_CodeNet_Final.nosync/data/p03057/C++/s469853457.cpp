#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int n,m,k,f[N],ans;char str[N];
int main(){
	scanf("%d%d%s",&n,&m,str+1);
	k=n;while(m&&str[m]==str[1])--m;
	if(!m)ans=1;
	for(int i=1,j=1;i<=m;i=j=j+1)
		if(str[i]==str[1]){
			while(j<m&&str[j+1]==str[1])++j;
			if(i==1)
				if(j-i+1&1)k=min(k,j-i+1);
				else k=min(k,j-i+2);
			else
				if(j-i+1&1)k=min(k,j-i+1);
		}
	if(k==n){
		for(int i=f[0]=1,j=0;i<=n;++i){
			f[i]=j;j=(j+f[i-1])%mod;
		}
		for(int i=2;i<=n;++i)
			ans=(ans+1ll*i*f[n-i])%mod;
	}else{
		++k;
		for(int i=2,j=f[0]=1;i<=n;i+=2){
			f[i]=j;j=(j+f[i])%mod;
			if(i>=k)j=(j-f[i-k]+mod)%mod;
		}
		for(int i=2;i<=k;i+=2)
			ans=(ans+1ll*i*f[n-i])%mod;
	}
	printf("%d\n",ans);
	return 0;
}
