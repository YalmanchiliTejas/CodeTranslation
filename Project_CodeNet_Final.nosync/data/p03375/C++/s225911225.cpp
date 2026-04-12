#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=3e3+3;
int S[N][N],C[N][N],pw[N*N];
int fpw(int x,int y,int P){
    int s=1; for (;y;y>>=1,x=(ll)x*x%P) if (y&1) s=(ll)s*x%P; return s;
}
int main(){
    int n,P; cin>>n>>P;
    S[0][0]=1;
    rep(i,1,n+1)
        rep(j,1,i) S[i][j]=((ll)j*S[i-1][j]+S[i-1][j-1])%P;
    rep(i,0,n+1){
        C[i][0]=1;
        rep(j,1,n+1) C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
    }
    pw[0]=1; rep(i,1,n*n) pw[i]=2LL*pw[i-1]%P;
    int ans=0;
    rep(i,0,n){
        int t=0;
        rep(j,0,i) t=(t+(ll)pw[(n-i)*j]*S[i+1][j+1])%P;
        t=(ll)t*fpw(2,fpw(2,n-i,P-1),P)%P*C[n][i]%P;
        if (i&1) ans=(ans+P-t)%P;
        else ans=(ans+t)%P;
    }
    cout<<ans<<endl;
    return 0;
}
