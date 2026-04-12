#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
int n,mod;
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
int f[3010][3010],F[3010],C[3010][3010],p2[3010],P2[9000010];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	n=gi(),mod=gi();
	for(int i=0,p=1;i<=n;++i,p=p*2%(mod-1))p2[i]=pow(2,p);
	C[0][0]=1;
	for(int i=1;i<=n;++i){C[i][0]=1;for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;}
	f[0][0]=1;
	P2[0]=1;for(int i=1;i<=n*n;++i)P2[i]=P2[i-1]*2%mod;
	for(int i=1;i<=n+1;++i)
		for(int j=1;j<=i;++j)
			f[i][j]=(f[i-1][j-1]+1ll*f[i-1][j]*j)%mod;
	int ans=0;
	for(int i=0;i<=n;++i)
		for(int k=0;k<=i;++k)
			inc(ans,1ll*C[n][i]%mod*(i&1?mod-1:1)%mod*f[i+1][k+1]%mod*P2[(n-i)*k]%mod*p2[n-i]%mod);
	printf("%d\n",ans);
	return 0;
}
