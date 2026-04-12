#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LD double
#define LL long long
#define Re register int
using namespace std;
const int N=1e4+3,P=998244353;
int n,m,T,ans,cnt1,cnt2,jc[N],dp[N][N];char A[N],B[N];
inline void in(Re &x){
    int f=0;x=0;char c=getchar();
    while(c<'0'||c>'9')f|=c=='-',c=getchar();
    while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
    x=f?-x:x;
}
inline int mi(Re x,Re k){
	Re s=1;
	while(k){
		if(k&1)s=(LL)s*x%P;
		x=(LL)x*x%P,k>>=1;
	}
	return s;
}
inline int inv(Re x){return mi(x,P-2);}
inline int C(Re m,Re n){return (LL)jc[n]*inv(jc[m])%P*inv(jc[n-m])%P;}
int main(){
//	freopen("123.txt","r",stdin);
	scanf("%s%s",A+1,B+1),n=strlen(A+1),jc[0]=1;
	for(Re i=1;i<=n;++i)cnt1+=(A[i]=='1'&&B[i]=='1'),cnt2+=(A[i]=='1'&&B[i]=='0'),jc[i]=(LL)jc[i-1]*i%P;
	for(Re j=0;j<=cnt2;++j)dp[0][j]=(LL)jc[j]*jc[j]%P;
	for(Re i=1;i<=cnt1;++i)
		for(Re j=1;j<=cnt2;++j)
			dp[i][j]=((LL)dp[i-1][j]*i%P*j%P+(LL)dp[i][j-1]*j%P*j%P)%P;
	Re ans=0;
	for(Re i=0;i<=cnt1;++i)
		(ans+=(LL)dp[cnt1-i][cnt2]*jc[i]%P*jc[i]%P*C(i,cnt1)%P*C(i,cnt1+cnt2)%P)%=P;
	printf("%d\n",ans);
}