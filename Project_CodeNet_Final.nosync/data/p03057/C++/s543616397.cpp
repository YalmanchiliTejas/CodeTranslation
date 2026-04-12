#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005,M=1e9+7;
int n,m,f[N],g[N],ans;
char s[N];
signed main(){
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	if (s[1]=='R'){
		for (int i=1;i<=m;i++){
			if (s[i]=='R')s[i]='B';
			else s[i]='R';
		}
	}
	int l=0,mi=0;
	for (int i=1;i<=m;i++)
		if (s[i]=='R'){
			l=i-1;
			break;
		}
	if (!l){
		f[0]=g[0]=1;
		for (int i=1;i<=n;i++){
			f[i]=g[i-2];
			g[i]=(g[i-1]+f[i])%M;
		}
		for (int i=2;i<=n;i++)(ans+=i*f[n-i])%=M;
		printf("%lld\n",(ans+1)%M);
		return 0;
	}
	mi=l+!(l%2);
	for (int i=1,j=1;i<=m;i=j){
		while (j<=m&&s[j]=='B')j++;
		if (j>m)break;
		if ((j-i)&1)mi=min(mi,j-i);
		while (j<=m&&s[j]=='R')j++;
	}
	if (n%2==1){
		puts("0");
		return 0;
	}
	mi=(mi+1)/2;
	n/=2;
	f[0]=g[0]=1;
	for (int i=1;i<=n;i++){
		f[i]=(g[i-1]-(i-mi-1<0?0:g[i-mi-1])+M)%M;
		g[i]=(g[i-1]+f[i])%M;
	}
	for (int i=1;i<=mi;i++)(ans+=i*2*f[n-i])%=M;
	printf("%lld\n",ans);
}