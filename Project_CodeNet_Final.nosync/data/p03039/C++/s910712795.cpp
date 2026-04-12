#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define miele(v) min_element(v.begin(), v.end())
#define maele(v) max_element(v.begin(), v.end())
#define SUM(v) accumulate(v.begin(), v.end(), 0LL)
#define lb(a, key) lower_bound(a.begin(),a.end(),key)
#define ub(a, key) upper_bound(a.begin(),a.end(),key)
#define COUNT(a, key) count(a.begin(), a.end(), key) 
#define BITCOUNT(x) __builtin_popcount(x)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
using P = pair <int,int>;
using WeightedGraph = vector<vector <P>>;
using UnWeightedGraph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int MOD = 1000000007;
void YN(bool flg) {cout<<(flg?"YES":"NO")<<'\n';}
void Yn(bool flg) {cout<<(flg?"Yes":"No")<<'\n';}
void yn(bool flg) {cout<<(flg?"yes":"no")<<'\n';}
template <typename T> 
int getIndexOfLowerBound(vector <T> &v, T x){
    return lower_bound(v.begin(),v.end(),x)-v.begin();
}
template <typename T> 
int getIndexOfUpperBound(vector <T> &v, T x){
    return upper_bound(v.begin(),v.end(),x)-v.begin();
}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
#define DUMPOUT cerr
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
template <typename T, typename U>
istream &operator>>(istream &is, pair<T,U> &p_var) {
    is >> p_var.first >> p_var.second;
    return is;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec) is >> x;
    return is;
}
template <typename T>
istream &operator>>(istream &is, vector<vector<T>> &df) {
    for(int i=0;i<df.size();i++)for(int j=0;j<df[i].size();j++)
    is >> df[i][j];
    return is;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
    DUMPOUT<<'{';
    os << pair_var.first;
    DUMPOUT<<',';
    os << " "<< pair_var.second;
    DUMPOUT<<'}';
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &vec) {
    DUMPOUT<<'[';
    for (int i = 0; i < vec.size(); i++) 
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
    DUMPOUT<<']';
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<vector<T>> &df) {
  for (auto& vec : df) os<<vec;
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
    DUMPOUT << "{";
    repi(itr, map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) DUMPOUT << ", ";
        itr--;
    }
    DUMPOUT << "}";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var) {
    DUMPOUT << "{";
    repi(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) DUMPOUT << ", ";
        itr--;
    }
    DUMPOUT << "}";
    return os;
}
void print() {cout << endl;}
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(tail) != 0) cout << " ";
  print(forward<Tail>(tail)...);
}
void dump_func() {DUMPOUT << '#'<<endl;}
template <typename Head, typename... Tail>
void dump_func(Head &&head, Tail &&... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) DUMPOUT << ", ";
    dump_func(std::move(tail)...);
}
#ifdef DEBUG_
#define DEB
#define dump(...)                                                              \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                            \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
            << endl                                                            \
            << "    ",                                                         \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif
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
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};
using mint = Fp<1000000007>;
const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
signed main(void) { cin.tie(0); ios::sync_with_stdio(false);
    int n, m, k; cin>>n>>m>>k;
    mint ans = 0;
    COMinit();
    mint add = m;
    add *= (m*m-1);
    add *= n*n;
    add *= COM(n*m-2, k-2);
    add /= 6;
    ans += add;
    dump(ans);
    add = n;
    add *= (n*n-1);
    add *= m*m;
    add *= COM(n*m-2, k-2);
    add /= 6;
    ans += add;
    //ans += n*(n*n-1)*m*m*COM(n*m-2, k-2)/6;
    print(ans);
}
