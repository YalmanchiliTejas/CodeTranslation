#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> pa;
#define w1 first
#define w2 second
#define ls (x<<1)
#define rs (x<<1|1)
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define SZ(x) ((x).size())
#define All(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define rep2(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define per(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define Rep(p,x) for(int (p)=head[(x)];(p);(p)=nxt[(p)])
template<class T>void read(T&num){
	num=0;T f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
	num*=f;
}
int power(int x,int k,int p){int res=1;for(;k;k>>=1,x=1ll*x*x%p)if(k&1)res=1ll*res*x%p;return res;}
int getgcd(int x,int y){return !x?y:getgcd(y%x,x);}
const int maxn=1e4+5,mod=998244353;
int n,cnt0,cnt1;
char A[maxn],B[maxn];
int fac[maxn],ifac[maxn],f[maxn];
int main(){
	scanf("%s",A+1);
	scanf("%s",B+1);
	n=strlen(A+1);
	rep(i,1,n){
		if(A[i]=='1'&&B[i]=='0')cnt0++;
		if(A[i]=='1'&&B[i]=='1')cnt1++;
	}
	fac[0]=1;rep(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
	rep(i,0,n)ifac[i]=power(fac[i],mod-2,mod);
	f[0]=1;
	rep(i,1,cnt0)rep(j,1,cnt1)f[j]=(f[j]+1ll*i*f[j-1])%mod;
	int ans=0;
	rep(j,0,cnt1)ans=(ans+1ll*f[j]*ifac[cnt0+j])%mod;
	ans=1ll*ans*fac[cnt0+cnt1]%mod;
	printf("%lld\n",1ll*ans*fac[cnt0]%mod*fac[cnt0]%mod*fac[cnt1]%mod);
	return 0;
}