#include<bits/stdc++.h>
using namespace std;
#define FOR(i,n,m) for(int i=(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define all(vec) vec.begin(),vec.end()
using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using P=pair<int,int>;
using PP=pair<int,P>;
#define pb push_back
#define fi first
#define se second
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1LL<<60;
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
vl siz;
vl met;
void init(int n){
    siz.resize(n+1);
    met.resize(n+1);
    siz[0]=1;
    met[0]=1;
    REP(i,n){
        siz[i+1]=siz[i]*2+3;
        met[i+1]=met[i]*2+1;
    }
}
ll dfs(ll n,ll m){//レベルnの上位m
    if(!n){
        return 1;
    }
    if(m==siz[n]){
        return met[n];
    }
    ll res=0;
    if(m>1){
        res+=dfs(n-1,min(m-1,siz[n-1]));
    }
    if(m>=siz[n-1]+2){
        res++;
    }
    if(m>siz[n-1]+2){
        res+=dfs(n-1,min(m-siz[n-1]-2,siz[n-1]));
    }
    return res;
}
int main(){
    ll n,m;
    cin>>n>>m;
    init(n);
    cout<<dfs(n,m)<<endl;
    return 0;
}