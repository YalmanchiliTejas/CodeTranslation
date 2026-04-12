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
const int MOD = (int) 998244353;
const int MAXN =(int) 3e3+10;
const int MAXM = (int) 3e6+10;

///--------------------START-------------------------
int N,S;
int a[MAXN];
LL dp[MAXN];

void work(){
    scanf("%d%d",&N,&S);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    LL ans=0;
    for(int i=1;i<=N;i++){
        for(int j=S;j>=a[i];j--){
            dp[j]=(dp[j]+dp[j-a[i]])%MOD;
        }
        if(a[i]<=S) dp[a[i]]=(dp[a[i]]+i)%MOD;
//        printf("i = %d: ",i);
//        for(int k=1;k<=S;k++) printf("%lld ",dp[k]);
//        printf("\n");
//        printf("sumL = %lld, add = %lld\n",dp[S],dp[S]*(N-i+1));
        ans=(ans+dp[S])%MOD;
    }
    printf("%lld\n",ans);
}

///--------------------END-------------------------
int main(){
#ifdef NNever
//freopen("data.in","r",stdin);
///freopen("out.txt","w",stdout);
#endif // NNever
    work();
    return 0;
}



