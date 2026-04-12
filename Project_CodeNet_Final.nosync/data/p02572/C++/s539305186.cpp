#include <bits/stdc++.h>
using namespace std;

//定数
const long long MOD1=1000000007;
const long long MOD2=998244353;
const long double PI=3.1415926535897932;
const long long MAXLL=9223372036854775807;
const long long INF=2305843009213693951;
const long long dx[]={0,1,0,-1,1,-1,1,-1};
const long long dy[]={1,0,-1,0,1,1,-1,-1};

//省略
#define ll long long
#define ull unsigned long long
#define ld long double
#define uld unsigned long double
#define pll pair<long long,long long>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vvvl vector<vector<vector<long long>>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vs vector<string>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vp vector<pair<long long,long long>>
#define umap unordered_map
#define uset unordered_set
#define Lqueue priority_queue<long long>
#define Squeue priority_queue<long long,vector<long long>,greater<long long>>
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back

//マクロ
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rbf(a,x) for(auto& a:x)
#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s);i<(long long)(n);i++)
#define bitrep(i,s,n) for(long long i=(s);i<(1LL<<(n));i++)
#define bitcheck(bit,i) (bit)&(1LL<<(i))
#define Maxe(x) *max_element((x).begin(),(x).end())
#define Mine(x) *min_element((x).begin(),(x).end())
#define Size(x) ((long long)(x).size())
#define Lin(s) getline(cin,(s))

//Yes,No
void Yes(bool a){cout<<(a?"Yes":"No")<<endl;}
void YES(bool a){cout<<(a?"YES":"NO")<<endl;}

//MAX,MIN
template<class T,class U> auto max(T a,U b){return a>b?a:b;}
template<class T,class U> auto min(T a,U b){return a<b?a:b;}

//最大公約数,最小公倍数
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
long long lcm(long long a,long long b){return a/gcd(a,b)*b;}

//切り上げ除算
long long cutup(long long a,long long b){return (a+b-1)/b;}

//累乗
template<typename t>
constexpr t my_pow(t a,long long b){
    if(b==0)return 1;
    if(a==0)return 0;
    t x=1;
    while(b>0){
        if(b&1LL)x*=a;
        a*=a;
        b>>=1LL;
    }
    return x;
}
#define pow my_pow

//chmin,chmax
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

//組み合わせ O(r)
template<typename t>
constexpr t nCr(t n,long long r){
    if(r==0)return 1;
    if(n==0)return 0;
    if(n<r)return 0;
    t x=1;
    for(long long i=1;i<=r;i++){
        x*=n-i+1;
        x/=i;
    }
    return x;
}

//MODint
template<long long MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr long long getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }

    friend constexpr istream& operator >> (istream &is, Fp<MOD>& x){
        long long t;
        is >> t;
        x=t;
        return (is);
    }
};
using mint = Fp<MOD1>;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    vl A(n);
    rep(i,n)cin>>A[i];
    mint res=0;
    vector<mint> sumA(n,0);
    sumA[0]=A[0];
    rep(i,n-1){
        sumA[i+1]=A[i+1];
        sumA[i+1]+=sumA[i];
    }
    rep(i,n){
        mint a=sumA[n-1]-sumA[i];
        a*=A[i];
        res+=a;
    }
    cout<<res<<endl;
}