#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;

vector<pll> dp(100);

ll dfs(ll n,ll x){
    if(x==0){return 0;}
    if(dp[n].F<=x){return dp[n].S;}
    x--;
    ll ans=0;
    ans+=dfs(n-1,x);
    x-=dp[n-1].F;
    if(x>0){
        ans++; x--;
        if(x>0){ans+=dfs(n-1,x);}
    }
    return ans;
}



int main(){
    dp[0]={1,1};
    for(int i=1;i<100;i++){
        dp[i]=dp[i-1];
        dp[i].F*=2; dp[i].S*=2;
        dp[i].F+=3; dp[i].S+=1;
    }
    ll n,x;
    cin>>n>>x;
    cout<<dfs(n,x)<<endl;
    
    
    
    return 0;
}
