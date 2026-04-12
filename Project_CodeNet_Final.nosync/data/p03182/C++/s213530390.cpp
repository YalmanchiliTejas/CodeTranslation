#define RUN
#ifdef RUN
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#define _CRT_SECURE_NO_DEPRECATE
#endif

#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using Trie = trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

int readint()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    num=num * flag;
    return num;
}

ll readll()
{
    ll num = 0ll; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    num=num * flag;
    return num;
}

typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > ppi;
typedef pair<ld,ld> pdd;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ld> vd;
typedef vector<pii> vpii;
typedef vector<vector<pii> > vvpii;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef vector<pdd> vdd;
typedef vector<cd> vcd;
typedef vector<ppi> vppi;

#define vv vector<vector<
#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x)  beg(x), en(x)
#define resz(x,a)  x.resize(a)
#define pb push_back
#define as(x,a) x.assign(a)

#define F0R(i,a) for(int i=0;i<(a);++i)
#define FOR(i,a,b) for(int i=a;i<(b);++i)
#define FORD(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define F0RD(i,a) for(int i=(a)-1;i>=0;--i)
#define trav(a,x) for(auto& a : x)

#define fi first
#define se second
#define mp make_pair


#define lb lower_bound
#define ub upper_bound

const int mod = 1000000007;    /// mod NTT (FFT) 998244353
const ll oo = 1e18;
const ld pi= acos(-1);

int power(int a, ll b) { ll res=1ll; for(;b;b>>=1,a=a*a%mod)  if(res&1) res=res*a%mod; return res;}

template<class T> void chmax(T&a, T b)  {a=max(a,b);}
template<class T> void chmin(T&a, T b)  {a=min(a,b);}
template<class T> T gcd(T a, T b)  {return b==0 ? a : gcd(b,a%b);}
template<class T> T lcm(T a, T b)  {return a*(b/gcd(a,b));}

void Input(string s) { freopen(s.c_str(),"r",stdin); }
void Output(string s){ freopen(s.c_str(),"w",stdout);}

class segtree
{
private:
    int n;
    struct node
    {
        ll val, lazy;
    };
    vector<node> st;
    int left(int p) { return p<<1;}
    int right(int p) { return left(p)|1;}
    void down(int p)
    {
        for( int u : {left(p), right(p)})
        {
            st[u].lazy+=st[p].lazy;
            st[u].val+=st[p].lazy;
        }
        st[p].lazy=0;
    }
    void update(int p, int l, int r, int i, int j, ll x)
    {
        if(i>j)  return ;
        if(i==l&&j==r)
        {
            st[p].val+=x;
            st[p].lazy+=x;
        }
        else
        {
            down(p);
            int mid=(l+r)>>1;
            update(left(p),l,mid,i,min(mid,j),x);
            update(right(p),mid+1,r,max(i,mid+1),j,x);
            st[p].val=min(st[left(p)].val,st[right(p)].val);
        }
    }
    ll query(int p, int l, int r, int i, int j)
    {
        if(i>j)  return oo;
        if(i<=l&&r<=j) return st[p].val;
        int mid=(l+r)>>1;
        down(p);
        return min(query(left(p),l,mid,i,min(j,mid)),query(right(p),mid+1,r,max(i,mid+1),j));
    }
public:
    segtree(const int& _n) {n=_n,  st.resize(n<<2,{0,0});}
    void update(int i, int j, ll val) { update(1,0,n-1,i,j,val);}
    ll query(int i, int j) { return query(1,0,n-1,i,j);}
};
int n, m;
const int N=2*100000 +5;
vpii v[N];
int main()
{
    //Input("inp");
    int l, r, a;
    ll sum=0ll;
    scanf("%d%d",&n,&m);
    segtree st(n+2);
    for(int i=0;i<m;++i)
    {
        l=readint();  r=readint();  a=readint();
        sum+=a;
        v[r].push_back({l,a});
    }
    ll tmp=0;
    for(int i=1;i<=n+1;++i)
    {
        for(int j=0;j<v[i-1].size();++j) st.update(0,v[i-1][j].fi-1,v[i-1][j].se);
        tmp=st.query(0,i-1);
        st.update(i,i,tmp);
    }
    cout<<sum-tmp;
    return 0;
}
