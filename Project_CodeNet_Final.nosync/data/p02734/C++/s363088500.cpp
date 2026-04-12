#include<bits/stdc++.h>

#define fi first
#define sd second
#define lson (nd<<1)
#define rson (nd<<11)
#define PB push_back
#define mid (l+r>>1)
#define MP make_pair
#define SZ(x) (int)x.size()

using namespace std;

typedef long long LL;

typedef vector<int> VI;

typedef pair<int,int> PII;

inline int read(){
    int res=0, f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){res=res*10+ch-'0';ch=getchar();}
    return res*f;
}

//化相等关系为不等关系，dp[i][j]表示右端点至多为i的时候，和为j的子序列左端点的和
//滚动掉一维，

const int MAXN = 3'005;

const int MOD = 998244353;

void modadd(int& a, int b){a+=b;if(a>=MOD)a-=MOD;}
int modmul(int a, int b){return 1ll*a*b%MOD;}

int dp[MAXN];

int n, s;

int A[MAXN];

int main(){
    n=read();s=read();
    for(int i=1;i<=n;++i)A[i]=read();

    int ans=0;

    for(int i=1;i<=n;++i){
        int t=dp[s];
        for(int j=s;j>=1;--j){//反向，不然会更新错误
            if(j==A[i])modadd(dp[j],i);
            if(j>A[i]){
                modadd(dp[j],dp[j-A[i]]);
            }
        }
        modadd(ans,modmul(dp[s]-t+MOD,n-i+1));//差分表示右端点恰好为i的时候，其和为s的多端点的和
    }
    cout<<ans;

    return 0;
}
