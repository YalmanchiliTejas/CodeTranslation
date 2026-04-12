#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
 

ll dpp[53];
ll dp[53];

ll rec(ll level,ll x){
    if(level == 0)return 1;
    if(x<=1)return 0;
    if(x<1+dp[level-1]+1)return rec(level-1,x-1);
    if(x==dp[level-1]+2)return 1+dpp[level-1];
    if(x==dp[level])return dpp[level];
    return dpp[level-1]+1+rec(level-1,x-(2+dp[level-1]));
}

int main(void){
    dp[0]=1;
    dpp[0]=1;
    for(ll i=1;i<=50;i++){
        dp[i]=2*dp[i-1]+3;
        dpp[i]=2*dpp[i-1]+1;
    }
    ll n,x;
    cin>>n>>x;
    cout<<rec(n,x)<<endl;
    return 0;
}