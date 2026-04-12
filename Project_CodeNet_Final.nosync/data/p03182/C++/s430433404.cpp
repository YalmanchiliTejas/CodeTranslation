#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a),i##formax=(b);i<i##formax;i++)
#define FORR(i,a,b) for(int i=(a),i##formax=(b);i>=i##formax;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pcnt __builtin_popcount
#define sz(x) (int)(x).size()
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)
#define show(x) cout<<#x<<" = "<<x<<endl;
#define all(a) (a.begin()),(a.end())
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define perm(c) sort(all(c));for(bool c##p=1;c##p;c##p=next_permutation(all(c)))
#define bitComb(a,n,k) for(int a##x,a##y,a=(1<<k)-1;a<(1<<n);a##x=a&-a,a##y=a+a##x,a=(((a&~a##y)/a##x)>>1)|a##y)
#define uniq(v) sort(all(v));v.erase(unique(all(v)), v.end())
#define bit(n) (1LL<<(n))
#define randInt(l,r) (uniform_int_distribution<ll>(l,r)(rnd))
#define randDouble(l,r) (uniform_real_distribution<double>(l,r)(rnd))
#define dout(d) printf("%.12f\n",d)

typedef long long ll;
typedef __int128_t lll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T>using V=vector<T>;
template<class T>using VV=V<V<T>>;
template<class T,class Y>ostream& operator<<(ostream& o,const pair<T,Y>& p){return o<<"("<<p.fi<<", "<<p.se<<")";}
template<typename A,size_t N,typename T>void Fill(A (&array)[N],const T&v){fill((T*)array,(T*)(array+N),v);}
lll gcd(lll a,lll b,lll &x,lll &y){if(!b){x=1;y=0;return a;}lll d=gcd(b,a%b,y,x);y-=a/b*x;return d;}
ll gcd(ll a,ll b){lll x=0,y=0;return gcd(a,b,x,y);}
ll modInv(ll a,ll m){lll x,y;gcd(a,m,x,y);return (x%m+m)%m;}
ll modPow(lll a,lll n,ll m){if(!a)return a;lll p=1;for(;n>0;n>>=1,a=a*a%m)if(n&1)p=p*a%m;return(ll)p;}
bool isPrime(ll n){if(n<2||n%2==0)return n==2;lll t=n-1,d=t/(t&-t);for(lll a:{2,325,9375,28178,450775,9780504,1795265022})if(a%n){for(t=d,a=modPow(a,t,n);t!=n-1&&a!=1&&a!=n-1;a=a*a%n,t=t*2%n);if(a!=n-1&&t%2==0)return 0;}return 1;}
const int IINF = 1e9+6;
const ll LINF = 1e18;
const int MOD = 1e9+7;
const double PI = acos(-1);
const double EPS = 1e-10;
static random_device rd;
static mt19937 rnd(rd());

struct StarrySky{
  typedef long long V;
  typedef long long B;
  const V EV = 0;
  const B EB = 0;

  V mVV(V a, V b){
    // node値同士のmerge. seg_treeと同様
    return max(a, b);
  }
  V mBV(V v, int l, B b){
    // node値v,長さlのnodeにbのbuffが掛かった後のnode値
    return v+b;
  }
  B mBB(B a, B b){
    // 既にaのbuffがかかっているnodeに加えてbのbuffが掛かった後のbuff値
    return a+b;
  }
  V uV(V v, int l){
    // vがl個入ったnodeの値. update時に使う
    return v;
  }
//###################################################
  int n;
  vector<V>    vv; // node値
  vector<V>    vl; // lazy値
  vector<B>    vb; // buff値
  vector<bool> vz; // lazy状態かどうか
  void init(int m){
    n = 1<<(32-__builtin_clz(m-1));
    vv = vector<V>(2*n-1, EV);
    vl.resize(2*n-1);
    vb = vector<B>(2*n-1, EB);
    vz = vector<bool>(2*n-1, false);
  }
  void init(vector<V>&v){
    init(v.size());
    for(int j=0; j<v.size(); j++) vv[j+n-1] = v[j];
    for(int j=n-2; j>=0; j--) vv[j] = mVV(vv[j*2+1], vv[j*2+2]);
  }
  inline void ref(int k, int l){
    int k1 = k*2+1, k2=k*2+2;
    l>>=1;
    if(vz[k]){
      vz[k1] = vz[k2] = true;
      vl[k1] = vl[k2] = vl[k];
      vb[k1] = vb[k2] = EB;
      vv[k1] = vv[k2] = uV(vl[k], l);
      vz[k] = false;
    }
    if(vb[k] != EB){
      vv[k1] = mBV(vv[k1], l, vb[k]); vb[k1] = mBB(vb[k1], vb[k]);
      vv[k2] = mBV(vv[k2], l, vb[k]); vb[k2] = mBB(vb[k2], vb[k]);
      vb[k] = EB;
    }
  }
  V _buff(int a,int b,int k,int l,int r, B v){
    if(r<=a||b<=l){
    }else if(a<=l&&r<=b){
      vv[k] = mBV(vv[k], r-l, v);
      vb[k] = mBB(vb[k], v);
    }else{
      ref(k, r-l);
      vv[k] = mVV(
          _buff(a, b, k*2+1, l, (l+r)/2, v),
          _buff(a, b, k*2+2, (l+r)/2, r, v)
          );
    }
    return vv[k];
  }
  void buff(int a, int b, B v){
    _buff(a, b, 0, 0, n, v);
  }
  V _update(int a, int b, int k, int l, int r, V v){
    if(r<=a||b<=l){
    }else if(a<=l&&r<=b){
      vv[k] = uV(v, r-l);
      vb[k] = EB;
      vz[k] = true;
    }else{
      ref(k, r-l);
      vv[k] = mVV(
          _update(a, b, k*2+1, l, (l+r)/2, v),
          _update(a, b, k*2+2, (l+r)/2, r, v)
          );
    }
    return vv[k];
  }
  void update(int a, int b, V v){
    _update(a, b, 0, 0, n, v);
  }
  V _query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return EV;
    if(a<=l&&r<=b) return vv[k];
    ref(k, r-l);
    return mVV(
        _query(a, b, k*2+1, l, (l+r)/2),
        _query(a, b, k*2+2, (l+r)/2, r)
        );
  }
  V query(int a,int b){
    return _query(a, b, 0, 0, n);
  }
} seg;
int n, m;
map<int, V<pii>> v;
main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  seg.init(n+1);
  FOR(i, 0, m){
    int l, r, a;
    cin >> l >> r >> a;
    v[r].pb(mp(l, a));
  }
  FOR(i, 1, n+1){
    seg.update(i, i+1, seg.query(0, i));
    for(pii&p:v[i]) seg.buff(p.fi, i+1, p.se);
  }
  cout << seg.query(0, n+1) << endl;
}