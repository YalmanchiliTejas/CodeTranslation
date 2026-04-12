#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define REP(a,b) for(int a=0;a<(b);++a)
#define REP1(i,n) for(int i=1;i<=(n);++i)
#define debug(x) cerr<<#x<<": "<<x<<'\n'
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define isYes(x) printf("%s\n",(x) ? "Yes" : "No")
#define isPossible(x) printf("%s\n",(x) ? "Possible" : "Impossible")
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define INF (1<<29)

// const long long INF = 1LL<<50;

#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define pie 3.14159265358979323846
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
template<class T=int>
T in(){T x;cin>>x;return (x);}
template<class T>
void print(T& x){cout<<x<<'\n';}

const int MOD =(int)1e9+7;
// const int mod =(int)998244353;
const int mod =(int)1e9+7;

const int MAX =510000;
ll fac[MAX],finv[MAX],inv[MAX];
void COMint(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
ll COM(int n,int k){
    if(n<k) return 0;
    if(n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
ll gcd(ll a,ll b){
    if(a<0)a=-a;
    if(b<0)b=-b;
    if(b==0)return a;
    if(a>b){
        swap(a,b);
    }
    return gcd(a,b%a);
}
ll lcm(ll a,ll b){
  if(a<0)a=-a;
  if(b<0)b=-b;
    ll g;g=gcd(a,b);
    return b/g*a;
}
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}
bool compare_by_a(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
struct mint {
   ll x; // typedef long long ll;
   mint(ll x=0):x((x%mod+mod)%mod){}
   mint& operator+=(const mint a) {
     if ((x += a.x) >= mod) x -= mod;
     return *this;
   }
   mint& operator-=(const mint a) {
     if ((x += mod-a.x) >= mod) x -= mod;
     return *this;
   }
   mint& operator*=(const mint a) {
     (x *= a.x) %= mod;
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
   mint inv() const {
     return pow(mod-2);
   }
   mint& operator/=(const mint a) {
     return (*this) *= a.inv();
   }
   mint operator/(const mint a) const {
     mint res(*this);
     return res/=a;
   }
 };
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
struct combination {
vector<mint> fact, ifact;
   combination(int n):fact(n+1),ifact(n+1) {
       assert(n < mod);
       fact[0] = 1;
       for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
       ifact[n] = fact[n].inv();
       for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
     }
     mint operator()(int n, int k) {
       if (k < 0 || k > n) return 0;
       return fact[n]*ifact[k]*ifact[n-k];
     }
}c(2000005);
//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;
int main() {
    ios::sync_with_stdio(false);
    int N=in();
    vector<mint>A(N);
    mint s=0;
    mint s_p=0;
    REP(i,N){
        cin>>A[i];
        s+=A[i];
        s_p+=A[i]*A[i];
    }
    cout<<(s*s-s_p)/2<<endl;
    return 0;
} 
 