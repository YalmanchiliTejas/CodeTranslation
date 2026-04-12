#include<bits/stdc++.h>
#define XX first
#define YY second
#define pb emplace_back
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define EFOR(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define REP rep
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef ll LL;
typedef pii PII;
typedef pll PLL;
const ll MOD=1e9+7;

#define rall(X) (X).rbegin(),(X).rend()
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}

template<ll mod>
struct ModInt{
  using M=ModInt;
  ll a;
  M& put(ll v){
    a=(v<mod)?v:v-mod;
    return *this;
  }
  ModInt(ll v=0){put(v%mod+mod);}
  M operator+(M x){return M().put(a+x.a);}
  M operator-(M x){return M().put(a+mod-x.a);}
  M operator*(M x){return M().put(a*x.a%mod);}
  M operator/(M x){return *this*x.inv();}
  M& operator+=(M x){return *this=*this+x;};
  M& operator-=(M x){return *this=*this-x;};
  M& operator*=(M x){return *this=*this*x;};
  M& operator/=(M x){return *this=*this/x;};
  bool operator==(M x){return a==x.a;}

  M pow(ll m){
    M x=*this,res=1;
    while(m){
      if(m&1)res*=x;
      x*=x;
      m>>=1;
    }
    return res;
  }
  M inv(){return pow(mod-2);}
};

using Int = ModInt<MOD>;

int N;
vector<LL> hs;
Int fact = 1;

struct Val {
  Int dp1;
  Int dp2;
};

struct Val Calc(vector<LL> &hs) {
  LL mh = 1LL << 40;
  for (LL h : hs) {
    MN(mh, h);
  }

  struct Val ret = {1, 1};
  vector<LL> vec;
  int w = 0;
  for (LL h : hs) {
    h -= mh;
    if (h > 0) {
      vec.eb(h);
    } else {
      ++w;
      assert(h == 0);
      if (vec.size()) {
        auto res = Calc(vec);
        ret.dp2 *= res.dp2 + res.dp1;
        ret.dp1 *= res.dp1;
      }
      vec.clear();
    }
  }

  if (vec.size()) {
    auto res = Calc(vec);
    ret.dp2 *= res.dp2 + res.dp1;
    ret.dp1 *= res.dp1;
  }

  Int g = Int(2).pow(w);
  ret.dp2 *= g;
  //cout << ret.dp1.a << ", " << ret.dp2.a << endl;
  Int t = Int(2).pow(mh);
  ret.dp2 += ret.dp1 * (t-2);
  ret.dp1 *= t;
  //cout << ret.dp1.a << ", " << ret.dp2.a << endl;
  return ret;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  cin >> N;
  rep(i, N) {
    LL h;
    cin >> h;
    hs.eb(h);
  }
  cout << (fact*Calc(hs).dp2).a << endl;
}
