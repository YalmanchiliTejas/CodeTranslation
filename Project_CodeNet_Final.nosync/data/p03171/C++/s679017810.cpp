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
#include<tuple>
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

vector<vector<ll>> dp;
vector<ll> a;

ll dfs(ll l,ll r,bool depth){
    if(l==r){return dp[l][r]=a[l]*(depth?-1:1);}
    if(dp[l][r]!=E){return dp[l][r];}
    if(depth){
        return dp[l][r]=min(dfs(l,r-1,!depth)-a[r],dfs(l+1,r,!depth)-a[l]);
    }
    return dp[l][r]=max(dfs(l,r-1,!depth)+a[r],dfs(l+1,r,!depth)+a[l]);
}


int main(){
    ll n;
    cin>>n;
    a.resize(n);
    for(auto &i:a){cin>>i;}
    dp.resize(n+1,vector<ll>(n+1,E));
    cout<<dfs(0,n-1,false)<<endl;
    
    
    return 0;
}
