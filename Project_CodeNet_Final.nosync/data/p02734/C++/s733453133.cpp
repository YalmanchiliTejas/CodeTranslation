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

const int MAXN = 3'005;

const int MOD = 998244353;

//这道题，如果考虑每一个区间段会相当复杂，应该考虑每一个和为s的上升子序列
//被多少个区间包括(算贡献)，这是一步很重要的转换
//dp[i][j]表示以i为右端点，和为j的左端点之和
//最终答案为sum(i=1...n)(n-i+1)dp[i][s]
//需要一个前缀和，不然时间上过不去

void addmod(int& a, int b){a+=b;if(a>=MOD)a-=MOD;}
int mulmod(int a, int b){return 1ll*a*b%MOD;}

int dp[MAXN][MAXN];

int pre[MAXN][MAXN];//1-i所有值为j的左端点之和

int n, s;

int A[MAXN];

int main(){
    n=read();s=read();
    for(int i=1;i<=n;++i)A[i]=read();

    for(int i=1;i<=n;++i){
        dp[i][A[i]]=i;
        pre[i][A[i]]=i;
    }

    for(int i=2;i<=n;++i){
        for(int j=1;j<=s;++j){
            addmod(pre[i][j],pre[i-1][j]);
        }
    }

    for(int j=2;j<=s;++j){
        for(int i=1;i<=n;++i)if(j>A[i]){
            addmod(dp[i][j],pre[i-1][j-A[i]]);
        }
        for(int i=1;i<=n;++i){//更新
            pre[i][j]=pre[i-1][j];
            addmod(pre[i][j],dp[i][j]);
        }
    }

    int ans=0;
    for(int i=1;i<=n;++i){
        addmod(ans,mulmod(n-i+1,dp[i][s]));
    }

    cout<<ans;

    return 0;
}
