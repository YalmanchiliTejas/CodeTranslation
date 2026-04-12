//by Sshwy
#include<algorithm>/*{{{*/
#include<cctype>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
namespace RA{
    int r(int p){return 1ll*rand()*rand()%p;}
    int r(int L,int R){return r(R-L+1)+L;}
}/*}}}*/
/******************heading******************/
int pw(int a,int m,int p){
    int res=1;
    while(m)m&1?res=1ll*res*a%p:0,a=1ll*a*a%p,m>>=1;
    return res;
}
const int N=3005;

int n,P;
int c[N][N],s[N][N];

int sig(int x){return 1-2*(x&1);}

int main(){
    cin>>n>>P;
    s[0][0]=c[0][0]=1;
    FOR(i,1,n+1){
        c[i][0]=1;
        FOR(j,1,i){
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%P;
            s[i][j]=(1ll*s[i-1][j]*j%P+s[i-1][j-1])%P;
            //printf("s[%d,%d]=%d\n",i,j,s[i][j]);
            //printf("c[%d,%d]=%d\n",i,j,c[i][j]);
        }
    }

    int ans=0;
    FOR(i,0,n){
        int x=0;
        FOR(k,0,i){
            x=(x+pw(pw(2,n-i,P),k,P)*1ll*s[i+1][k+1]%P)%P;
        }
        x=1ll*x*pw(2,pw(2,n-i,P-1),P)%P*sig(i)*c[n][i]%P;
        //printf("i=%d,x=%d\n",i,x);
        x=(x+P)%P;
        ans=(ans+x)%P;
    }

    printf("%d\n",ans);
    return 0;
}
