#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
#include<cassert>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int mod;

template<int unchi>
struct ModInt {
    long long x;
 
    ModInt() : x(0) {}
    ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    explicit operator int() const {return x;}
 
    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p) {
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }
 
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
 
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
 
    ModInt inverse() const{
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        return ModInt(u);
    }

    ModInt power(long long p) const{
        int a = x;
        if (p==0) return 1;
        if (p==1) return ModInt(a);
        if (p%2==1) return (ModInt(a)*ModInt(a)).power(p/2)*ModInt(a);
        else return (ModInt(a)*ModInt(a)).power(p/2);
    }

    ModInt power(const ModInt p) const{
        return ((ModInt)x).power(p.x);
    }

    friend ostream &operator<<(ostream &os, const ModInt<unchi> &p) {
        return os << p.x;
    }
    friend istream &operator>>(istream &is, ModInt<unchi> &a) {
        long long x;
        is >> x;
        a = ModInt<unchi>(x);
        return (is);
    }
};

using modint = ModInt<0>;

struct ModFac{
  public:
    vector<modint> f,i_f;
    int n;

    ModFac(int n_){
      n=n_;
      f.resize(n+1,1);
      i_f.resize(n+1,1);
      for(int i=0;i<n;i++){
        f[i+1]=f[i]*(modint)(i+1);
      }
      i_f[n]=f[n].power(mod-2);
      for(int i=n-1;i>=0;i--){
        i_f[i]=i_f[i+1]*(modint)(i+1);
      }
    }
    ModFac(modint n_){
      n=(int)n_;
      f.resize(n+1,1);
      i_f.resize(n+1,1);
      for(int i=0;i<n;i++){
        f[i+1]=f[i]*(modint)(i+1);
      }
      i_f[n]=f[n].power(mod-2);
      for(int i=n-1;i>=0;i--){
        i_f[i]=i_f[i+1]*(modint)(i+1);
      }
    }
    
    modint factorial(int x){
      //cout << f.size() << endl;
      return f[x];
    }
        
    modint inv_factorial(int x){
      return i_f[x];
    }
    
    modint comb(int m,int k){
      if (m<0 or k<0) return 0;
      if (m<k) return 0;
      return f[m]*i_f[k]*i_f[m-k];
    }
};


int n;
modint S[3010][3010];
modint po[3010];

void solve(){
    cin >> n >> mod;
    po[0]=2;
    rep(i,n) po[i+1]=po[i]*po[i];
    ModFac MF(10010);
    S[0][0]=1;
    //cout << S[0][0] << endl;
    rep(i,n){
        rep(j,n){
            S[i+1][j+1]=S[i][j]+((modint)(j+1))*S[i][j+1];
            //cout << i+1 << " " << j+1 << " " << S[i+1][j+1] << endl;
        }
    }
    modint ans=0;
    modint two=2; 
    Rep(m,1,n+1){
        modint res=0;
        Rep(i,1,m+1){
            modint T=two.power((ll)(n-m)*(ll)(i-1));
            res+=(modint)i*S[m][i]*T;
            res+=S[m][i]*T*two.power(n-m);
            //cout << m << " " << i << " " << res << endl;
        }
        res*=MF.comb(n,m)*po[n-m];
        //cout << m << " " << res << endl;
        if(m%2) ans+=res;
        else ans-=res;
    }
    cout << po[n]-ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}