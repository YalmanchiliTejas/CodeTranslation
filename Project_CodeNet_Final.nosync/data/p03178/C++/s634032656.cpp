#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define MAX ((ll)(1e18 + 5))
#define pi (2*acos(0))
#define mp make_pair
#define M ((int)(1e9 + 7))
#define xx first
#define yy second
#define NN ((ll)(1e6+2))
#define N ((int)(1e4 + 5))
#define eps 0
#define log 20
#define pb push_back
#define MOD 998244353


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long lu;

typedef tree < ll,  null_type,  less < ll >,  rb_tree_tag,  tree_order_statistics_node_update > o_set;

char s[N];

int dp[2][101][N], n;

int call(bool cmp, int mod, int i)
{
    if(s[i]=='\0'){
        if(mod==0) return 1;
        return 0;
    }
    if(dp[cmp][mod][i]!=-1) return dp[cmp][mod][i];
    dp[cmp][mod][i] = 0;
    int d = 9;
    if(cmp) d = s[i]-'0';
    for(; d>=0; d--){
        if(d<s[i]-'0' || cmp==0) dp[cmp][mod][i] += call(0,(mod+d)%n,i+1);
        else dp[cmp][mod][i] += call(1,(mod+d)%n,i+1);
        if(dp[cmp][mod][i]>=M) dp[cmp][mod][i] -= M;
    }
    return dp[cmp][mod][i];
}

int main()
{
    memset(dp,-1,sizeof dp);
    scanf("%s %d",s,&n);
    printf("%d\n",(M-1+call(1,0,0))%M);
    return 0;
}
