#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a),_ed=(b);i<=_ed;++i)
#define DREP(i,a,b) for(int i=(a),_ed=(b);i>=_ed;--i)
typedef long long ll;
inline int read(){
    register int x=0,f=1;register char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=0;ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch^'0');ch=getchar();}
    return f?x:-x;
}

const int N=1e4+5,mod=998244353;
int n,f[N][N],p,q,fac[N],ifc[N];
char A[N],B[N];
inline int power(int b,int n){int ans=1;for(;n;n>>=1,b=1ll*b*b%mod)if(n&1)ans=1ll*ans*b%mod;return ans;}
inline void inc(int &x,int y){x=x+y<mod?x+y:x+y-mod;}
inline int C(int n,int m){return (n<0||m<0||n<m)?0:1ll*fac[n]*ifc[m]%mod*ifc[n-m]%mod;}

int main(){
    //freopen("in.in","r",stdin);
    scanf("%s",A+1);scanf("%s",B+1);
    n=strlen(A+1);
    REP(i,fac[0]=1,N-1)fac[i]=1ll*fac[i-1]*i%mod;
    ifc[N-1]=power(fac[N-1],mod-2);
    DREP(i,N-2,0)ifc[i]=1ll*ifc[i+1]*(i+1)%mod;
    REP(i,1,n)p+=(A[i]=='1'&&B[i]=='1'),q+=(A[i]=='1'||B[i]=='1');
    q-=p;q>>=1;
    REP(j,0,q)f[0][j]=1ll*fac[j]*fac[j]%mod;
    REP(i,1,p)REP(j,1,q){
	if(j)inc(f[i][j],1ll*f[i][j-1]*j%mod*j%mod);
	inc(f[i][j],1ll*f[i-1][j]*i%mod*j%mod);
    }
    int ans=0;
    REP(i,0,p)inc(ans,1ll*f[p-i][q]*C(p,i)%mod*fac[i]%mod*fac[i]%mod*C(p+q,i)%mod);
    printf("%d\n",ans);
    return 0;
}
