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


ll n;
vector<pll> stp;
vector<vector<char>> A(4,vector<char>(4));

bool same(ll a,ll h,ll w,ll num){
    char c=0;
    for(ll i=max(h,0LL);i<4 && i-h<stp[num].F;i++){
        for(ll t=max(w,0LL);t<4 && t-w<stp[num].S;t++){
            if(a>>(i*4+t)&1){continue;}
            if(c==0){
                c=A[i][t];
            }
            else if(c!=A[i][t]){return false;}
        }
    }
    return true;
}

ll put(ll a,ll h,ll w,ll num){
    for(ll i=max(h,0LL);i<4 && i-h<stp[num].F;i++){
        for(ll t=max(w,0LL);t<4 && t-w<stp[num].S;t++){
            a|=1LL<<(i*4+t);
        }
    }
    return a;
}


int main(){
    cin>>n;
    stp.resize(n);
    for(auto &i:stp){cin>>i.F>>i.S;}
    for(auto &i:A){
        for(auto &t:i){cin>>t;}
    }
    vector<ll> dp(1LL<<16,E);
    queue<ll> Q;
    dp[0]=0;
    Q.push(0);
    while(!Q.empty()){
        ll W=Q.front();
        Q.pop();
        for(int i=0;i<n;i++){
            for(int h=-3;h<4;h++){
                for(int w=-3;w<4;w++){
                    ll next=put(W,h,w,i);
                    if(dp[next]==E && same(W,h,w,i)){
                        if(next==(1LL<<16)-1){cout<<dp[W]+1<<endl; return 0;}
                        dp[next]=dp[W]+1;
                        Q.push(next);
                    }
                }
            }
        }
    }
    
    
    
    return 0;
}

