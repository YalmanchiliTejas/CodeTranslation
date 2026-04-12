
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <list>
#include <bitset>
#include <vector>
using namespace std;

#define I64d_OJ

//#ifdef I64d_OJ
//#define LL __int64
//#endif // I64d_OJ
#ifdef I64d_OJ
#define LL long long
#endif // I64d_OJ

typedef unsigned LL ULL;
typedef unsigned uint;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pLL;
typedef vector<int> vi;

inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-f; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define ls rt<<1
#define rs rt<<1|1
#define MID(a,b) (((LL)(a)+(LL)(b))>>1)
#define absx(a) ((a)<0?-(a):(a))
#define MK(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define lowbit(x) ((x)&-(x))

#define lc c[x][0]
#define rc c[x][1]

template< typename T >
inline void Max(T &a,T &b){if(a<b) a=b;}
template< typename T>
inline void Min(T &a,T &b){if(a>b) a=b;}

const double pi=(double)acos(-1.0);
const double eps=(double)1e-8;
const int INF = (int) 0x3f3f3f3f;
const int MOD = (int) 1e9+7;
const int MAXN =(int) 2e5+10;
const int MAXM = (int) 3e6+10;

///--------------------START-------------------------
int N;
int a[MAXN];
LL dp[MAXN][2][2];

void work(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    LL ans=0;
    for(int i=0;i<=N;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++)
                dp[i][j][k]=1LL*(INF)*(INF)*(-1);
        }
    }
//    dp[0][0][0]=0;
//    dp[1][0][1]=a[1];
    dp[0][1][0]=0;
//    dp[0][1][1]=a[1];
    for(int i=1;i<=N;i++){
        if(i&1){
//            if(i==N){
//                dp[i][0][1]=dp[i-1][0][0]
//            }
            dp[i][0][0]=max(dp[i-1][0][1],dp[i-1][0][0]);
            dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][1][1]);
            dp[i][0][1]=dp[i-1][0][0]+a[i];
            dp[i][1][1]=dp[i-1][1][0]+a[i];
        }
        else{
            dp[i][0][0]=max(dp[i-1][0][1],dp[i-1][1][0]);
            dp[i][1][0]=dp[i-1][1][1];
            dp[i][0][1]=dp[i-1][0][0]+a[i];
            dp[i][1][1]=dp[i-1][1][0]+a[i];
        }
    }
//    for(int i=1;i<=N;i++){
//        printf("%lld %lld %lld %lld\n",dp[i][0][0],dp[i][0][1],dp[i][1][0],dp[i][1][1]);
//    }
    if(N&1){
//        if(N==1){
//            printf("%lld\n",0);
//        }
//        else{
        LL ans=max(dp[N][0][1],dp[N][1][0]);
        printf("%lld\n",ans);
//        }
    }
    else{
        LL ans=max(dp[N][1][0],dp[N][1][1]);
        printf("%lld\n",ans);
    }
}
/*
27
-49 57 59 -99 69 -93 -70 24 57 -77 49 -62 -26 35 -71 -74 28 60 -53 23 -45 90 -45 28 18 -28 18
*/
/*
7
1 2 3 4 10 5 8
*/
///--------------------END-------------------------
int main(){
#ifdef NNever
//freopen("data.in","r",stdin);
///freopen("out.txt","w",stdout);
#endif // NNever
    work();
    return 0;
}






