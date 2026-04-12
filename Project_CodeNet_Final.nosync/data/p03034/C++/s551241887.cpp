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
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef long double D;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;


int main(){
    ll n;
    cin>>n;
    vector<ll> A(n);
    for(auto &I:A){cin>>I;}
    vector<vector<ll>> dp(n);
    for(ll i=1;i<n;i++){
        dp[i].push_back(0);
        for(ll t=1;i*t<n;t++){
            ll x=dp[i].back();
            dp[i].push_back(x+A[n-1-i*t]);
        }
    }
    ll sum;
    ll ans=0;
    for(ll i=1;i<n;i++){
        sum=0;
        for(ll t=1;i*t<n;t++){
            sum+=A[i*t];
            ll a=(n-1-i*t);
            if(a<=i){continue;}
            if(a%i!=0 || i*t<a){
                ans=max(ans,sum+dp[i][t]);
            }
        }
    }
    cout<<ans<<endl;
    
    
    return 0;
}
