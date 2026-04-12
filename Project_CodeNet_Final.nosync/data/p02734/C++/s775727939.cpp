#pragma region head
    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
    using vi = vector<int>;
    using vll = vector<ll>;
    using pi = pair<int, int>;
    using pll = pair<ll,ll>;
    template <class T> using vv = vector<vector<T>>;
    #define rep(i,n) for(int i = 0; i < (int)(n); i++)
    #define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
    #define rrep(i,n) for(int i = (int)(n)-1; i >= 0; i--)
    #define rrepi(i,a,b) for(int i = (int)(b)-1; i >= (int)(a); i--)
    const int INF = 1002003004;
    const ll LINF = 1002003004005006007ll;
    struct preprocess{preprocess()
    {cin.tie(nullptr);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}}____;
#pragma endregion head

#pragma region library
const int MOD = 998244353;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%MOD+MOD)%MOD){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  // for prime MOD
  mint inv() const {
    return pow(MOD-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};
ostream& operator<< (ostream& os, const mint& value) {
  os << value.x;
  return os;
}

#pragma endregion library

int main(){
    int n,s; cin >> n >> s;
    vi a(n); rep(i,n) cin >> a[i];
    vector<mint> f(s+1);
    mint ans=0;
    rep(i,n){
        f[0]+=1;
        rrep(j,s+1){
            if(j+a[i]<s+1) f[j+a[i]]+=f[j];
        }
        ans+=f[s];
    }
    cout << ans << '\n';
    
}