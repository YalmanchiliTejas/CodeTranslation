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

string s;
ll mod;

vector<vector<ll>> dp;
vector<vector<ll>> dp2;

ll dfs(ll k,ll d,bool mx){
    if(mx){
        if(dp2[k][d]!=-1){return dp2[k][d];}
        ll c=s[k]-'0';
        if(k==0){
            ll count=0;
            for(ll i=0;i<=c;i++){
                if(i%mod==d){count++;}
            }
            return dp2[k][d]=count;
        }
        dp2[k][d]=0;
        for(ll i=0;i<c;i++){
            dp2[k][d]+=dfs(k-1,(d+mod*100-i)%mod,false);
        }
        dp2[k][d]+=dfs(k-1,(d+mod*100-c)%mod,true);
        return dp2[k][d]%=MOD;
    }
    else{
        if(dp[k][d]!=-1){return dp[k][d];}
        if(k==0){
            ll count=0;
            for(ll i=0;i<10;i++){
                if(i%mod==d){count++;}
            }
            return dp[k][d]=count;
        }
        dp[k][d]=0;
        for(int i=0;i<10;i++){
            dp[k][d]+=dfs(k-1,(d+mod*100-i)%mod,false);
        }
        return dp[k][d]%=MOD;
    }
    return -1;
}


int main(){
    cin>>s>>mod;
    reverse(s.begin(),s.end());
    dp.resize(s.size(),vector<ll>(mod,-1));
    dp2.resize(s.size(),vector<ll>(mod,-1));
    ll ans=dfs(s.size()-1,0,true)-1;
    ans%=MOD;
    if(ans<0){ans+=MOD;}
    cout<<ans<<endl;
    
    
    return 0;
}
