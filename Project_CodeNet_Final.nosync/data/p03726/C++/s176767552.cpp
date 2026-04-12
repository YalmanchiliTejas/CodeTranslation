#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define eb emplace_back
template<class T>void chmax(T &a,T b){if(a<b)a=b;}
template<class T>void chmin(T &a,T b){if(a>b)a=b;}
constexpr int INF=1000000000000000000;
constexpr int mod=1000000007;
constexpr double eps=1e-8;
const double pi=acos(-1);
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int Random(int mi,int ma){
    random_device rnd;
    mt19937 mt(rnd());//32bit
    //[mi,ma]
    uniform_int_distribution<int>engine(mi,ma);
    return engine(mt);
}
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
bool prime(int a){
    if(a==1)return false;
    for(int i=2;i*i<=a;i++){
        if(a%i==0)return false;
    }
    return true;
}
int modpow(int a,int b){
    if(b==0)return 1;
    if(b%2)return modpow(a,b-1)*a%mod;
    int memo=modpow(a,b/2);
    return memo*memo%mod;
}
vector<int>kaijo,invkaijo;
void init_fact(int n){
    kaijo.resize(n+1);
    invkaijo.resize(n+1);
    kaijo[0]=1;
    for(int i=1;i<=n;i++){
        kaijo[i]=kaijo[i-1]*i;
        kaijo[i]%=mod;
    }
    rep(i,n+1)invkaijo[i]=modpow(kaijo[i],mod-2);
}
int comb(int a,int b){
    if(a<b)return 0;
    if(a<0||b<0)return 0;
    return kaijo[a]*modpow(kaijo[a-b],mod-2)%mod*modpow(kaijo[b],mod-2)%mod;
}
int inv(int x){
    x=modpow(x,mod-2);
    return x;
}
int n,d[100010],par[100010];
bool used[100010],flag[100010];
vector<int>v[100010];
void dfs(int x){
    used[x]=true;
    for(int i:v[x]){
        if(!used[i]){
            d[i]=d[x]+1;
            par[i]=x;
            dfs(i);
        }
    }
}
signed main(){
    cin.tie(0);ios::sync_with_stdio(false);
    cin>>n;
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    fill(par,par+n,-1);
    dfs(0);
    priority_queue<P>q;
    rep(i,n)q.push({d[i],i});
    while(!q.empty()){
        P p=q.top();
        q.pop();
        if(flag[p.se])continue;
        if(p.se==0){
            puts("First");
            return 0;
        }
        if(flag[par[p.se]]){
            puts("First");
            return 0;
        }
        flag[par[p.se]]=true;
        flag[p.se]=true;
    }
    puts("Second");
    return 0;
}