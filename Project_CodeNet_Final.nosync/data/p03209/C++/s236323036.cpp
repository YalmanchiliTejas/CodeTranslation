#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;

ll dp[55];
ll dpp[55];
ll n,x;

ll rec(ll level,ll x){
    if(level==0){
        if(x<=0)return 0;
        else return 1;
    }
    else{
        if(x<=1+dp[level-1]){
            return rec(level-1,x-1);
        }
        else return dpp[level-1]+1+rec(level-1,x-dp[level-1]-2);
    }
}

int main(void){
    dp[0]=1;
    dpp[0]=1;
    for(ll i=1;i<55;i++){
        dp[i]=2*dp[i-1]+3;
        dpp[i]=2*dpp[i-1]+1;
    }
    cin>>n>>x;
    cout<<rec(n,x)<<endl;
}