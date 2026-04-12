#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;

vector<ll> al;
vector<ll> p;

ll dfs(ll X,int L){
    if(L==0)return X;
    if(X==0 || X==1)return 0;
    if(X>=al.at(L))return p.at(L);
    if(X>al.at(L-1)+1)return p.at(L-1)+1+dfs(X-al.at(L-1)-2,L-1);
    return dfs(X-1,L-1);
}

int main() {
    ll N,X;
    cin>>N>>X;
    al.resize(N+1);
    al.at(0)=1;
    rep(i,N+1){
        if(i)al.at(i)=al.at(i-1)*2+3;
    }
    p.resize(N+1);
    p.at(0)=1;
    rep(i,N+1){
        if(i)p.at(i)=p.at(i-1)*2+1;
    }
    cout<<dfs(X,N)<<endl;;
}