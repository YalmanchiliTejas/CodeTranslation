#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;



int main(){
    ll n,k,mod;
    cin>>n>>k>>mod;
    map<pair<deque<int>,int>, ll> dp[222];
    dp[0][{{0,1},1}]=1;
    rep(i,2*n-1){
        int nxt = i+2;
        for(auto& e : dp[i]){
            deque<int> f = e.first.first;
            int s = e.first.second;
            if(f.size()==1){
                if(f[0]+k<nxt)continue;
                f.push_back(nxt);
                dp[i+1][{f,s}]+=e.second%mod;   
            }
            else{
                if(s+k<nxt)continue;
                if(f[1]+k<nxt)continue;
                f.push_back(nxt);
                dp[i+1][{f,s}]+=e.second%mod;
                f.pop_back();
                f.pop_front();
                dp[i+1][{f,nxt}]+=e.second%mod;
            }
        }
        dp[i].clear();
    }
    ll ans = 0;
    rep(i,k){
        deque<int> f;
        f.push_back(2*n-1-i);
        ans += dp[2*n-1][{f,2*n}]%mod;
    }
    cout<<ans%mod<<endl;
    return 0;
}
