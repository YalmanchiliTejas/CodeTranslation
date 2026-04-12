#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007

using namespace std;
const int N=200010;
int n,m,ans,f[N],g[N];
char s[N];

void inc(int&x,int y){x+=y;if(x>=mod)x-=mod;}
void dec(int&x,int y){x-=y;if(x<0)x+=mod;}

int main(){
//	freopen("E.in","r",stdin);
//	freopen("E.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	int p=0;while(p<m&&s[p+1]==s[1])++p;
	if(p==m){
		ans=f[0]=g[0]=1;
		for(int i=0;i<=n;++i){
			if(i>1)f[i]=g[i-2];
			if(i)g[i]=(g[i-1]+f[i])%mod;
			if(n-i!=1)inc(ans,(ll)(n-i)*f[i]%mod);
		}
		cout<<ans<<endl;
	}else{
		if(n&1)puts("0"),exit(0);
		int L=p|1;
		while(1){
			int tmp=0;
			while(p<m&&s[p+1]!=s[1])++p;tmp-=p;
			while(p<m&&s[p+1]==s[1])++p;tmp+=p;
			if(p==m)break;
			if(tmp&1)L=min(L,tmp);
		}
		f[0]=g[0]=1;
		L=(L+1)>>1;n>>=1;
		for(int i=0;i<=n;++i){
			if(i)f[i]=g[i-1];
			if(i>L)dec(f[i],g[i-L-1]);
			if(i)g[i]=(g[i-1]+f[i])%mod;
			if(n-i<=L)inc(ans,(ll)(n-i)*f[i]%mod);
		}
		cout<<ans*2%mod<<endl;
	}
	return 0;
} 
