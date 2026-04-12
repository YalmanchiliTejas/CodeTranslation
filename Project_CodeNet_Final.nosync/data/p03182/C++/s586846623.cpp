#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//clock_t start=clock();clock_t end=clock();cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef pair<pii,pii> P;
typedef tuple<ll,ll,ll> tl;
typedef pair<double,double> pdd;
typedef vector<vector<ll>> mat;
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll mod5=1000000009;
ll inf=1LL<<62;
int iinf=1<<30;
double pi=3.141592653589793238462643383279L;
double eps=1e-14;
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
#define srep(itr,st) for(auto itr=st.begin();itr!=st.end();itr++)
#define mrep(itr,mp) for(auto& itr:mp)
#define Max(a,b) a=max(a,b)
#define Min(a,b) a=min(a,b)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define umh unordered_map<ll,ll,custom_hash>
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    ll c=gcd(a,b);
    return a*b/c;
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}
ll beki(ll n,ll k,ll md){
  ll ret=1;
  ll now=n;
    now%=md;
  while(k>0){
    if(k%2==1){
      ret*=now;
      ret%=md;
    }
    now*=now;
    now%=md;
    k/=2;
  }
  return ret;
}
ll gyaku(ll n,ll md){
  return beki(n,md-2,md);
}
ll poc(ll n){
    ll ret=0;
    ll u=n;
    while(u>0){
        ret+=u%2;
        u/=2;
        
    }
    return ret;
}
struct LST{
private:
    int n;
    vector<ll> node,lazy;
    vector<bool> flag;
public:
    LST(vector<ll> v){
        ll sz=v.size();
        n=1;while(n<sz)n*=2;
        node.resize(2*n-1);
        lazy.resize(2*n-1,0);
        flag.resize(2*n-1,false);
        rep(i,0,sz)node[i+n-1]=v[i];
        rrep(i,n-2,0)node[i]=max(node[i*2+1],node[i*2+2]);
    }
    void eval(ll k,ll l,ll r){
        if(flag[k]){
            node[k]+=lazy[k];
            if(r-l>1){
                lazy[2*k+1]+=lazy[k];
                lazy[2*k+2]+=lazy[k];
                flag[2*k+1]=flag[2*k+2]=true;
            }
            flag[k]=false;
            lazy[k]=0;
        }
    }
    void update(ll a,ll b,ll x,ll k=0,ll l=0,ll r=-1){
        if(r<0)r=n;
        eval(k,l,r);
        if(b<=l||r<=a)return;
        if(a<=l&&r<=b){
            lazy[k]=x;
            flag[k]=true;
            eval(k,l,r);
        }
        else{
            update(a,b,x,2*k+1,l,(l+r)/2);
            update(a,b,x,2*k+2,(l+r)/2,r);
            node[k]=max(node[2*k+1],node[2*k+2]);
        }
    }
    ll find(ll a,ll b,ll k=0,ll l=0,ll r=-1){
        if(r<0)r=n;
        eval(k,l,r);
        if(b<=l||a>=r)return -inf;
        if(a<=l&&b>=r)return node[k];
        ll m1=find(a,b,2*k+1,l,(l+r)/2);
        ll m2=find(a,b,2*k+2,(l+r)/2,r);
        return max(m1,m2);
    }
};

/*int main() {
    cin >> N >> Q;
    LazySegmentTree seg( vector<int>(N, INF) );
    for(int i=0; i<Q; i++) {
        int query; cin >> query;
        if(query == 0) {
            int s, t, x; cin >> s >> t >> x;
            seg.update(s, t+1, x);
        }
        else {
            int s, t; cin >> s >> t;
            cout << seg.find(s, t+1) << endl;
        }
    }
    return 0;
}*/
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll n,m;cin>>n>>m;
    vector<pll> v[n+1];
    rep(i,0,m){
        ll l,r,a;cin>>l>>r>>a;
        v[r].push_back({l,a});
    }
    LST seg(vector<ll>(n+1,0));
    rep(i,1,n+1){
        ll t=seg.find(0,i);
        seg.update(i,i+1,t);
        rep(j,0,v[i].size()){
            ll le=v[i][j].first,co=v[i][j].second;
            seg.update(le,i+1,co);
        }
    }
    ll ans=-inf;
    rep(i,0,n+1)Max(ans,seg.find(i,i+1));
    cout<<ans<<endl;
}
