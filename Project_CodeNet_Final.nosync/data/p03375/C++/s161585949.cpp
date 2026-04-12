#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#define db double
#define LL long long
#define inf 0x3f3f3f3f
#define N 3005
using namespace std;
int gi()
{
    int res=0,s=1; char ch;
    for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
    if(ch=='-') s=-1,ch=getchar();
    for(;ch>='0'&&ch<='9';ch=getchar()) res=res*10+ch-48;
    return res*s;
}
int n,mo;LL S[N][N],C[N][N],ans,tmp;
LL qp1(LL x,LL y) {
    LL res=1;
    for(;y;y>>=1,x=x*x%mo)
	if(y&1) res=res*x%mo;
    return res;
}
LL mmod(LL x,LL y) {
    LL res=x*y;
    return res>=(mo-1)?res%(mo-1)+(mo-1):res;
}
LL qp2(LL x,LL y) {
    LL res=1;
    for(;y;y>>=1,x=mmod(x,x))
	if(y&1) res=mmod(res,x);
    return res;
}
int main()
{
    n=gi(),mo=gi();
    S[0][0]=1;
    for(int i=1;i<=n+1;++i)
	for(int j=1;j<=i;++j)
	    S[i][j]=S[i-1][j-1]+S[i-1][j]*j%mo,S[i][j]>=mo?S[i][j]-=mo:0;
    C[0][0]=1;
    for(int i=1;i<=n;++i) {
	C[i][0]=C[i][i]=1;
	for(int j=1;j<i;++j)
	    C[i][j]=C[i-1][j]+C[i-1][j-1],C[i][j]>=mo?C[i][j]-=mo:0;
    }
    for(int i=0;i<=n;++i) {
	tmp=0;
	for(int j=0;j<=i;++j) {
	    tmp+=S[i+1][j+1]*qp1(2,(n-i)*j)%mo;
	    tmp>=mo?tmp-=mo:0;
	}
	tmp=tmp*C[n][i]%mo*qp1(2,qp2(2,n-i))%mo;
	if(i&1) ans+=mo-tmp; else ans+=tmp;
	ans>=mo?ans-=mo:0;
    }
    printf("%lld\n",ans);
    return 0;
}
