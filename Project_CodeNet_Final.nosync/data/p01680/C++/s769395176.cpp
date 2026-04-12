#include<bits/stdc++.h>
using namespace std;

class UnionFind{
    vector<int> par;
    vector<int> rank;
    public:
    UnionFind(int n):par(n),rank(n){
        iota(par.begin(),par.end(),0);
    }
    int find(int x){
        if(par[x]==x) return x;
        else return par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x),y=find(y);
        if(x==y) return;
        if(rank[x]<rank[y]) par[x]=y;
        else{
            if(rank[x]==rank[y]) rank[x]++;
            par[y]=x;
        }
    }
};
using ll=long long;
const ll MOD=1e9+7;
ll powm(ll x,ll k){
    ll res=1;
    for(int i=0;i<k;i++) res=(res*x)%MOD;
    return res;
}
ll solve(int n,int m){
    UnionFind u(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        u.unite(a,b);
    }
    vector<int> cnt(n);
    for(int i=0;i<n;i++){
        cnt[u.find(i)]++;
    }
    int maxV=*max_element(cnt.begin(),cnt.end());
    if(maxV>=2){
        int rest=count(cnt.begin(),cnt.end(),1);
        int chunk=0;
        for(int i=0;i<n;i++) if(cnt[i]>1) chunk++;
        return (powm(2,rest)*powm(2,chunk)+1)%MOD;
    }
    else{
        return powm(2,n);
    }
}
int main(){
    int n,m;
    while(cin>>n>>m,n){
        cout<<solve(n,m)<<endl;
    }
}
