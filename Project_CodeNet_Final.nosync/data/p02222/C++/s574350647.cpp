// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vec2(a,b) vector<vec>(a,vec(b))
#define vec2ll(a,b) vector<vec>(a,vecll(b))
#define vec3(a,b,c) vector<vector<vec>>(a,vec2(b,c))
#define vec3ll(a,b,c) vector<vector<vecll>>(a,vec2ll(b,c))
#define fi first
#define se second
#define endl "\n"
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))
#define MM " "
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}




vector<vec> g;
int t;
int num[2];
const int INF=1e6;
pii dfs(int x,int p){
    pii res={-INF,-INF};
    if(g[x].size()==1)res.fi=0;
    for(auto e:g[x]){
        if(e==p)continue;
        pii p=dfs(e,x);
        if(chmax(num[1],res.fi+p.fi)){
            if(num[1]>num[0])swap(num[0],num[1]);
        }
        if(chmax(num[1],res.fi+p.se)){
            if(num[1]>num[0])swap(num[0],num[1]);
        }
        if(chmax(num[1],res.se+p.fi)){
            if(num[1]>num[0])swap(num[0],num[1]);
        }
        vec v=vec{p.fi,p.se,res.fi,res.se};
        sort(all(v));
        reverse(all(v));
        res.fi=v[0],res.se=v[1];
    }
    // cout<<x<<" ";
    // print(res);cout<<endl;
    res.fi++;
    if(res.se!=-INF)res.se++;
    return res;
}

vec d;
int ma,mem,cen;
bool dfs2(int x,int p,int s){
    d[x]=s;
    if(chmax(ma,s))mem=x;
    if(g[x].size()==1 and g[x][0]==p and s==ma)return true;
    bool res=false;
    for(auto e:g[x]){
        if(e==p)continue;
        if(dfs2(e,x,s+1)){
            if(s == ma/2)cen = x;
            res=true;
        }
    }
    return res;
}
int dfs3(int x,int p,int s){
    if(g[x].size()==1 and s==ma/2-1) return 1;
    int res=0;
    for(auto e:g[x]){
        if(e==p)continue;
        res+=dfs3(e,x,s+1);
    }
    return res;
}

main(){
    int n=in();
    d.resize(n);
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    g.resize(n);
    rep(i,n-1){
        int a=in(),b=in();
        g[a-1].pb(b-1);
        g[b-1].pb(a-1);
    }
    d.resize(n);
    ma=0;
    dfs2(0,-1,0);
    dfs2(mem,-1,0);
    cen = 0;
    dfs2(mem,-1,0);
    dfs(mem,-1);
    int m=num[1];
    // cout<<num[0]<<" "<<num[1]<<endl;
    int cnt=0;
    int aaa;
    rep(i,n){
        if(g[i].size()>2)aaa=i,cnt++;
    }
    if(cnt==0){
        m=1;
    }
    if(num[0]%2==0 and num[1]==num[0]){
        bool check=true;
        for(auto e:g[cen]){
            // cout<<dfs3(e,cen,0)<<endl;
            if(dfs3(e,cen,0)>1) check=false;
        }
        if(check)m--;
    }
    string S(n,'0');
    S[0]='1',S[1]='1';
    rep2(i,m,n-1)S[i]='1';
    cout<<S<<endl;
}

