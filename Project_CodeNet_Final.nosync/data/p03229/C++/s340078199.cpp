#include <bits/stdc++.h>
using namespace std;

//定数
const long long MOD1=1000000007;
const long long MOD2=998244353;
const long long INF=1152921504606846976;
const long double PI=3.1415926535897932;

//型名省略
#define ll long long
#define ull unsigned long long
#define ld long double
#define pll pair<long long,long long>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define umap unordered_map
#define uset unordered_set
#define Lqueue priority_queue<long long>
#define Squeue priority_queue<long long,vector<long long>,greater<long long>>
#define Fi first
#define Se second

//マクロ
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rbf(a,x) for(auto& a:x)
#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s);i<(long long)(n);i++)
#define Maxe(x) *max_element((x).begin(),(x).end())
#define Mine(x) *min_element((x).begin(),(x).end())
#define Size(x) ((long long)(x).size())

//最大公約数
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}

//最小公倍数
long long lcm(long long a,long long b){return a/gcd(a,b)*b;}

//累乗
template<typename Num>
constexpr Num mypow(Num a,ll b){
    if(b==0)return 1;
    if(a==0)return 0;
    Num x=1;
    while(b>0){
        if(b&1)x*=a;
        a*=a;
        b>>=1;
        }
    return x;
}

//chmin,chmax
template<class T>
inline bool chmin(T& a,T b){
    if(a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T>
inline bool chmax(T& a,T b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

//MODint
template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
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

    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};
using mint = Fp<MOD1>;

    //start
    signed main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        ll n;
        cin>>n;
        vl A(n);
        rep(i,n)cin>>A[i];
        sort(all(A));
        vl S((n+1)/2);
        vl L(n/2);
        rep(i,n){
            if(i%2==0)S[i/2]=A[i/2];
            else L[i/2]=A[n-1-i/2];
        }
        deque<ll> Q;
        Q.push_front(S[0]);
        rep(i,n/2){
            if(i%2==0){
                Q.push_front(L[i]);
                if(i+1<Size(S)){
                    Q.push_front(S[i+1]);
                }
            }else{
                Q.push_back(L[i]);
                if(i+1<Size(S)){
                    Q.push_back(S[i+1]);
                }
            }
        }
        ll res=0;
        ll now=Q.front();
        Q.pop_front();
        while (!Q.empty())
        {
            ll a=Q.front();
            Q.pop_front();
            res+=abs(now-a);
            now=a;
        }

        //逆
        vl S2(n/2);
        vl L2((n+1)/2);
        rep(i,n){
            if(i%2==0)L2[i/2]=A[n-1-i/2];
            else S2[i/2]=A[i/2];
        }
        deque<ll> Q2;
        Q2.push_front(L2[0]);
        rep(i,n/2){
            if(i%2==0){
                Q2.push_front(S2[i]);
                if(i+1<Size(L2)){
                    Q2.push_front(L2[i+1]);
                }
            }else{
                Q2.push_back(S2[i]);
                if(i+1<Size(L2)){
                    Q2.push_back(L2[i+1]);
                }
            }
        }
        ll res2=0;
        ll now2=Q2.front();
        Q2.pop_front();
        while (!Q2.empty())
        {
            ll a=Q2.front();
            Q2.pop_front();
            res2+=abs(now2-a);
            now2=a;
        }
        chmax(res,res2);
        cout<<res<<endl;
    }