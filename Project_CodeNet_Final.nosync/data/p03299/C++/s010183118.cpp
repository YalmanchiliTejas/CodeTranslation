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
typedef long long lld;
typedef long double lf;
typedef unsigned long long uld;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
namespace RA{
    int r(int p){return 1ll*rand()*rand()%p;}
    int r(int L,int R){return r(R-L+1)+L;}
}/*}}}*/
/******************heading******************/
const int N=105,P=1e9+7;
typedef long long LL;

int n;
int a[N];
LL c[N][N];//区间[l,r]，以r结尾的段的个数
LL f[N][N];//f[i,j]:前i个数，末尾j个是极长的交错段的方案数
LL pw(LL a,LL m){
    LL res=1;
    while(m)m&1?res=res*a%P:0,a=a*a%P,m>>=1;
    return res;
}


int main(){
    scanf("%d",&n);
    FOR(i,1,n)scanf("%d",&a[i]);
    a[0]=1;
    FOR(r,1,n){
        if(a[r]<=a[r+1])continue;
        int lim=a[r+1];
        int cur=a[r];
        ROF(i,r-1,0){
            if(a[i]<cur){
                c[i+1][r]+=cur-max(a[i],lim);
                cur=max(a[i],lim);
            }
            c[i][r]=c[i+1][r];
        }
    }
    //FOR(i,1,n)FOR(j,1,i)if(c[j][i])printf("c[%d,%d]=%lld\n",j,i,c[j][i]);
    f[1][1]=pw(2,c[1][1])*2%P;
    FOR(i,1,n){
        FOR(j,2,i){
            f[i][j]=f[i-1][j-1]*1ll*pw(2,c[i-j+1][i])%P;
            //printf("f[%d,%d]=%lld\n",i,j,f[i][j]);
        }
        FOR(j,1,i-1){
            f[i][1]=(f[i][1]+f[i-1][j]*pw(2,c[i][i]))%P;
        }
        //printf("f[%d,%d]=%lld\n",i,1,f[i][1]);
    }
    LL ans=0;
    FOR(i,1,n)ans=(ans+f[n][i])%P;
    printf("%lld\n",ans);
    return 0;
}
