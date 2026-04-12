#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
ll int MOD=1e9+7;
#define N 200000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

int par[N],rrank[N];
void init(int n){
    rep(i,n){
        par[i]=i;
        rrank[i]=0;
    }
}
int root(int x){
    return par[x]==x?x:par[x]=root(par[x]);
}
bool same(int x,int y){
    return root(x)==root(y);
}
void unite(int x,int y){
    x=root(x); y=root(y);
    if(x==y)return;
    if(rrank[x]<rrank[y]){
        par[x]=y;
    }
    else{
        par[y]=x;
        if(rrank[x]==rrank[y]) rrank[x]++;
    }
}
main(){
    int n;
    vector<pii> v1,v2;
    cin>>n;
    rep(i,n){
        int a,b;
        scanf("%d %d",&a,&b);
        v1.push_back({a,i}); v2.push_back({b,i});
    }
    sort(v1.begin(),v1.end()); sort(v2.begin(),v2.end());
    vector<pair<int,pii>> v;
    rep(i,n-1){
        v.push_back({v1[i+1].first-v1[i].first,{v1[i].second,v1[i+1].second}});
        v.push_back({v2[i+1].first-v2[i].first,{v2[i].second,v2[i+1].second}});
    }
    sort(v.begin(),v.end());
    init(n+1);
    ll int ans=0; int uf=1;
    for(int i;uf<n;i++){
        int a=v[i].second.first,b=v[i].second.second;
        if(same(a,b)) continue;
        unite(a,b);
        uf++;
        ans+=v[i].first;
    }
    cout<<ans;
    return 0;
}