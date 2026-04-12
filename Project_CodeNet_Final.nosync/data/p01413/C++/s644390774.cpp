#include<bits/stdc++.h>

using namespace  std;

struct I{I(){ios::sync_with_stdio(false);cin.tie(0);}}init;

typedef long long LL;
typedef vector<LL> V;

const LL INF=1145141919;
V TSP(V &x,V &y){
    int n=x.size();
    V res(1<<n,INF);
    vector<V> tsp(n,V(1<<n,INF));
    V ord((1<<n)-1);
    iota(ord.begin(),ord.end(),1);
    sort(ord.begin(),ord.end(),[&](int l,int r){return __builtin_popcount(l)<__builtin_popcount(r);});
    for(int i=0;i<n;i++)tsp[i][1<<i]=abs(x[i])+abs(y[i]);
    for(auto &bit:ord){
        for(int i=0;i<n;i++){
            res[bit]=min(res[bit],tsp[i][bit]+abs(x[i])+abs(y[i]));
            for(int j=0;j<n;j++){
                int c=1<<j;
                tsp[j][bit|c]=min(tsp[j][bit|c],tsp[i][bit]+abs(x[i]-x[j])+abs(y[i]-y[j]));
            }
        }
    }
    return res;
}
LL knapsack(V cost,V value,int limit){
    int n=cost.size();
    LL res=0;
    V dp(limit+1,0);
    for(int i=0;i<n;i++)
        for(int j=cost[i];j<=limit;j++)
            res=max(dp[j]=max(dp[j],dp[j-cost[i]]+value[i]),res);
    return res;
}


int main(){
    int N,M,W,T;
    cin>>N>>M>>W>>T;
    V w(M),v(M);
    map<string,int> StoI;
    for(int i=0;i<M;i++){
        string s;
        cin>>s>>w[i]>>v[i];
        StoI[s]=i;
    }
    V x(N),y(N);
    vector<V> valdp(1<<N,V(M,0));
    V val(1<<N,0);
    for(int i=0;i<N;i++){
        int L;cin>>L>>x[i]>>y[i];
        while(L--){
            string s;LL vv;cin>>s>>vv;
            int id=StoI[s];
            vv=max(0ll,v[id]-vv);
            valdp[1<<i][id]=vv;
        }
    }
    auto t=TSP(x,y);
    for(int bit=1;bit<(1<<N);bit++){
        int rest=bit;
        while(rest){
            int now=rest&-rest;
            for(int i=0;i<M;i++)
                valdp[bit][i]=max(valdp[bit][i],valdp[now][i]);
            rest-=now;
        }
        val[bit]=knapsack(w,valdp[bit],W);
    }
    cout<<knapsack(t,val,T)<<endl;
    return 0;
}