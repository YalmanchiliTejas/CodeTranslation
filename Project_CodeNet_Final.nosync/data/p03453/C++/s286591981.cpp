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




int main(){
    ll n,m;
    cin>>n>>m;
    ll s,t;
    cin>>s>>t;
    s--; t--;
    vector<vector<pll>> edge(n); //行き先、距離
    for(int i=0;i<m;i++){
        ll u,v,d;
        cin>>u>>v>>d;
        u--; v--;
        edge[u].push_back({v,d});
        edge[v].push_back({u,d});
    }
    vector<pll> dp(n,{E,0}); //距離、通り数
    priority_queue<pll,vector<pll>,greater<pll>> q; //距離、場所
    q.push({0,s});
    dp[s]={0,1};
    while(!q.empty()){
        pll w=q.top();
        q.pop();
        if(w.F>dp[w.S].F){continue;}
        for(const auto &e:edge[w.S]){
            if(dp[e.F].F>w.F+e.S){
                dp[e.F].F=w.F+e.S;
                dp[e.F].S=dp[w.S].S;
                q.push({dp[e.F].F,e.F});
            }
            else if(dp[e.F].F==w.F+e.S){
                dp[e.F].S+=dp[w.S].S;
                dp[e.F].S%=MOD;
            }
        }
    }
    vector<pll> dps(n,{E,0}); //距離、通り数
    q.push({0,t});
    dps[t]={0,1};
    while(!q.empty()){
        pll w=q.top();
        q.pop();
        if(w.F>dps[w.S].F){continue;}
        //cout<<w.S<<" "<<dps[w.S].F<<endl;
        for(auto &e:edge[w.S]){
            if(dps[e.F].F>w.F+e.S){
                dps[e.F].F=w.F+e.S;
                dps[e.F].S=dps[w.S].S;
                q.push({dps[e.F].F,e.F});
            }
            else if(dps[e.F].F==w.F+e.S){
                dps[e.F].S+=dps[w.S].S;
                dps[e.F].S%=MOD;
            }
        }
    }
    //for(int i=0;i<n;i++){cout<<dps[i].F<<endl;}
    ll ans=dp[t].S*dps[s].S%MOD;
    //cout<<ans<<endl;
    for(int i=0;i<n;i++){
        if(dp[i].F==dps[i].F && dp[i].F*2==dp[t].F){
            //cout<<dp[i].S*dp[i].S%MOD*dps[i].S%MOD*dps[i].S%MOD<<endl;
            ans-=dp[i].S*dp[i].S%MOD*dps[i].S%MOD*dps[i].S;
            ans%=MOD;
        }
        for(const auto &e:edge[i]){
            if(i>e.F){continue;}
            ll a=i,b=e.F;
            if(dp[a].F*2<dp[t].F && dp[b].F*2>dp[t].F && dp[a].F+e.S==dp[b].F && dp[a].F+dps[a].F==dp[t].F && dp[b].F+dps[b].F==dp[t].F){
                ans-=dp[a].S*dp[a].S%MOD*dps[b].S%MOD*dps[b].S;
                ans%=MOD;
            }
            swap(a,b);
            if(dp[a].F*2<dp[t].F && dp[b].F*2>dp[t].F && dp[a].F+e.S==dp[b].F && dp[a].F+dps[a].F==dp[t].F && dp[b].F+dps[b].F==dp[t].F){
                ans-=dp[a].S*dp[a].S%MOD*dps[b].S%MOD*dps[b].S;
                ans%=MOD;
            }
        }
    }
    ans%=MOD;
    if(ans<0){ans+=MOD;}
    cout<<ans<<endl;
    
    
    
    return 0;
}
