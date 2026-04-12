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




int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> dark(n,-1);
    vector<ll> d(m);
    for(int i=0;i<m;i++){
        ll a;
        cin>>a;
        a--;
        dark[a]=i;
        d[i]=a;
    }
    vector<vector<ll>> edge(n,vector<ll>(k));
    for(auto &i:edge){
        for(auto &t:i){
            cin>>t;
            t-=1;
        }
    }
    vector<ll> dp(1LL<<m,E);
    dp.back()=0;
    queue<ll> Q;
    Q.push((1LL<<m)-1);
    while(!Q.empty()){
        ll w=Q.front();
        Q.pop();
        for(int i=0;i<k;i++){
            ll next=0;
            for(int t=0;t<m;t++){
                if((w>>t&1) && (dark[edge[d[t]][i]]>=0)){
                    next|=1LL<<dark[edge[d[t]][i]];
                }
            }
            if(dp[next]>dp[w]+1){
                if(next==0){cout<<dp[w]+1<<endl; return 0;}
                dp[next]=dp[w]+1;
                Q.push(next);
            }
        }
    }
    cout<<dp[0]<<endl;
    
    
    
    return 0;
}

