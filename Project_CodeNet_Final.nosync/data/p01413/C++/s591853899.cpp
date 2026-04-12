#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll INF=1e15;
void cmax(ll& x,ll y){
    x=max(x,y);
}
ll knapsack(int N,int W,vector<ll> w,vector<ll> v){
    vector<vector<ll>> dp(N+1,vector<ll>(W+1,0));
    dp[0][0]=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<=W;j++){
            cmax(dp[i+1][j],dp[i][j]);
            if(j+w[i]<=W) cmax(dp[i+1][j+w[i]],dp[i+1][j]+v[i]);
        }
    }
    return *max_element(dp[N].begin(),dp[N].end());
}
int main(){
    int n,m,w,t;
    cin>>n>>m>>w>>t;
    vector<string> s(m);
    vector<ll> v(m),p(m);
    for(int i=0;i<m;i++){
        cin>>s[i]>>v[i]>>p[i];
    }
    vector<int> l(n),x(n),y(n);
    vector<vector<string>> r(n);
    vector<vector<ll>> q(n);
    for(int i=0;i<n;i++){
        cin>>l[i]>>x[i]>>y[i];
        r[i].resize(l[i]),q[i].resize(l[i]);
        for(int j=0;j<l[i];j++) cin>>r[i][j]>>q[i][j];
    }
    vector<ll> income(1<<n,0);
    for(int bit=0;bit<(1<<n);bit++){
        vector<ll> wv,vv;
        for(int i=0;i<n;i++){
            if((bit>>i)&1){
                for(int j=0;j<l[i];j++){
                    for(int k=0;k<m;k++){
                        if(r[i][j]==s[k]){
                            wv.push_back(v[k]);
                            vv.push_back(p[k]-q[i][j]);
                        }
                    }
                }
            }
        }
        income[bit]=knapsack(wv.size(),w,wv,vv);
    }
    
    vector<ll> tourDist(1<<n,INF);
    {
       vector<vector<ll>> dp(1<<n,vector<ll>(n,INF));
       auto dist=[&](int i,int j){
           return abs(x[i]-x[j])+abs(y[i]-y[j]);
       };
       for(int i=0;i<n;i++) dp[1<<i][i]=abs(x[i])+abs(y[i]);
       for(int bit=0;bit<(1<<n);bit++){
           for(int i=0;i<n;i++){
               tourDist[bit]=min(tourDist[bit],dp[bit][i]+abs(x[i])+abs(y[i]));
               for(int j=0;j<n;j++){
                   dp[bit|(1<<j)][j]=min(dp[bit|(1<<j)][j],dp[bit][i]+dist(i,j));
               }
           }
       }
    }

    cout<<knapsack(1<<n,t,tourDist,income)<<endl;
    return 0;
}
