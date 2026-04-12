#include <bits/stdc++.h>
using namespace std;
 
#define int long long
//#define uint __int128_t
 
#define pb push_back
#define fi first
#define se second
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
#define low(a,b) lower_bound(all(a),(b))-(a).begin()
#define upp(a,b) upper_bound(all(a),(b))-(a).begin()
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<vint> vvint;
typedef vector<pint>vpint;
typedef pair<pint,int> P1;
typedef pair<int,pint> P2;
typedef pair<pint,pint> PP;
static const ll maxLL = (ll)1 << 62;
const ll MOD=1000000007;
const ll INF=1e18;
 
int N,M;
vpint g[200020];
struct LazySegmentTree{
    private:
    int n;
    vector<ll> node,lazy;


    public:
    LazySegmentTree(vector<ll> v){
        int sz = (int)v.size();
        n = 1;while(n < sz)n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1,0);

        for(int i=0;i<sz;i++)node[i+n-1] = v[i];
        for(int i=n-2;i>=0;i--)node[i]=max(node[2*i+1],node[2*i+2]);
    }

    void eval(int k,int l,int r){
        if(lazy[k] != 0){
            node[k] += lazy[k];

            if(r-l > 1){
                lazy[2*k+1] += lazy[k];
                lazy[2*k+2] += lazy[k];
            }
            lazy[k] = 0;
        }
    }

    void add(int a,int b,ll x,int k=0,int l=0,int r=-1){
        if(r<0)r = n;

        eval(k,l,r);
        if(b <= l || r <= a)return;

        if(a <= l && r <= b){
            //SUMじゃなければ+= xで更新
            lazy[k] += x;
            eval(k,l,r);
        }
        else{
            add(a,b,x,2*k+1,l,(l+r)/2);
            add(a,b,x,2*k+2,(l+r)/2,r);
            node[k] = max(node[2*k+1],node[2*k+2]);
        }
    }
    ll getmax(int a,int b,int k=0,int l=0,int r=-1){
        if(r < 0)r = n;
        if(b <= l || r <= a)return 0;
        eval(k,l,r);
        if(a <= l && r <= b)return node[k];
        ll vl = getmax(a,b,2*k+1,l,(l+r)/2);
        ll vr = getmax(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
};

signed main() {
    IOS();
    //(1ll<<N)シフト演算のオーバーフローに気をつける
    //MOD同士の引き算に注意
    cin>>N>>M;
    vint a(M),l(M),r(M);
    LazySegmentTree seg(vint(N+2,0));
    rep(i,0,M){
        cin>>l[i]>>r[i]>>a[i];
        r[i]--;l[i]--;
        g[r[i]].pb(pint(l[i],a[i]));
    }
    
    rep(i,0,N){
        int now=0;
        if(i)chmax(now,seg.getmax(0,i));
        //cout<<now<<endl;
        seg.add(i,i+1,now);
        for(auto e:g[i]){
            seg.add(e.fi,i+1,e.se);
        }
    }
    cout<<max(0ll,seg.getmax(0,N+1))<<endl;
    
    
    
    
    
    
    
    
    
    return 0;
}