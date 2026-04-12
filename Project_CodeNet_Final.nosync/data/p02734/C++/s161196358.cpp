#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N,S;
    cin>>N>>S;
    vector<int> A(N);
    rep(i,N){cin>>A.at(i);}
    vector<vector<ll>> dp(N+1,vector<ll>(S+1));
    dp.at(0).at(0)=1;
    rep(i,N){
        dp.at(i+1).at(0)++;
        
        rep(j,S+1){
            dp.at(i+1).at(j)+=dp.at(i).at(j);
            dp.at(i+1).at(j)%=MOD2;
            if(j+A.at(i)<=S){
                dp.at(i+1).at(j+A.at(i))+=dp.at(i).at(j);
                dp.at(i+1).at(j+A.at(i))%=MOD2;
            }
        }
    }
    
    ll ans=0;
    rep(i,N+1){
        ans+=dp.at(i).at(S);
        ans%=MOD2;
    }
    cout<<ans<<endl;
}