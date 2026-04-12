
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
LL dp[3005][3005];
int vis[3005][3005];
int a[3005];
LL DP(int l,int r){
    if(l>r)return 0;
    if(vis[l][r])return dp[l][r];
    dp[l][r]=max(a[r]-DP(l,r-1),a[l]-DP(l+1,r));
    vis[l][r]=1;
    return dp[l][r];
}
int main(){
    int n;
    scanf("%d",&n);
    MEM(vis);
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    printf("%lld\n",DP(1,n));
}
