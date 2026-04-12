#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <set>
#include <utility>
#include <functional>
#include<cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int,pii> P;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
const int MAXN = 100000;
const int MAXE = 100000;
const int MAXV = 10000;
const int inf = 1e9;
const ll INF = 2e18;
const ll MOD = 1e9 + 7;

struct UnionFind{
    vector<int> par,rank;
    UnionFind(int n):par(n),rank(n){
        for(int i=0;i<n;++i) par[i]=i;
    }
    int root(int x){
        if(par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    void unite(int x,int y){
        int rx=root(x),ry=root(y);
        if(rx==ry) return ;
        if(rank[ry]>rank[rx]) par[rx]=ry;
        else par[ry]=rx;
        if(rank[rx]==rank[ry]) rank[rx]++;
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
};

vector<ll> fac,inv,finv;

void initcom(){
    fac=inv=finv=vector<ll>(1e6);
    fac[0]=fac[1]=1;
    inv[1]=1;
    finv[0]=finv[1]=1;
    for(ll i=2;i<1e6;++i){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

ll com(int n,int k){
    if(n<0||k<0) return 0;
    if(n<k) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
ll gcd(ll x,ll y){
    if(y==0) return x;
    return gcd(y,x%y);
}
ll mopow(ll a,ll x,ll mod){
    ll res=1;
    while(x>0){
        if(x&1) res=res*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return res;
}

bool warp[5][5];
int maze[3010][3010];
int cnt[3010][3010];
int h,w;
vector<string> s;
int c;
void dfs(int y,int x){
    cnt[y][x]=c;
    for(int i=0;i<4;++i){
        int ny=y+dy[i],nx=x+dx[i];
        if(!(ny>=0&&ny<h&&nx>=0&&ny<w)) continue;
        if(s[ny][nx]=='#') continue;
        if(cnt[y][x]>0) continue;
        dfs(ny,nx);
    }
}
int main(){
    int n;cin>>n;
    vector<ll> a(n),s(n,0);
    for(int i=0;i<n;++i){
        cin>>a[i];
        if(i<n-1){
            s[i+1]=s[i]+a[i];
            s[i+1]%=MOD;
        }
    }
    ll ans=0;
    for(int i=1;i<n;++i){
        ans+=a[i]*s[i]%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}
