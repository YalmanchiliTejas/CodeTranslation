#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long LL;
typedef pair<int,int> PII;
#define X first
#define Y second
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}
const int MOD=1000000007;
int n;
LL a[200010],sum,ans,pro; 
LL quickpow(LL a,int N,int mod)
{
    LL res=1,tmp=a;
    while(N)
    {
        if(N&1)res=(res*tmp)%mod;
        tmp=(tmp*tmp)%mod;
        N>>=1;
    }
    return res;
} 
LL Inv(LL a){return quickpow(a,MOD-2,MOD);}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),sum=(sum+a[i])%MOD,pro=(pro+(a[i]*a[i])%MOD)%MOD;
	printf("%lld\n",(sum*sum%MOD-pro+MOD)*Inv(2)%MOD);
	return 0;
}
/*

*/
