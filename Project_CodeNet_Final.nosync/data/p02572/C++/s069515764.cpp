#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
using pcc = pair<char, char>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using tuplis = array<ll, 3>;
template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;
const ll LINF=0x1fffffffffffffff;
const ll MINF=0x7fffffffffff;
const ll LPLMT=10000000;//O(n)のloop上限
const ll NLGLMT=200000;//O(NlogN)のloop上限（これで指定されたfor文の中にO(logN)の処理を書く）
const ll N2LMT=3000;//O(n^2)のloop上限
const ll N3LMT=100;//O(n^3)のloop上限
const ll N4LMT=50;//O(n^4)のloop上限
const ll TNLMT=20;//O(2^n)のloop上限（実際この計算量になるのは全探索くらいなので，この値自体を使うことはなさそう）（オーダの参考程度に）
const int INF=0x3fffffff;
const int MOD=1000000007;
const int MODD=998244353;
const ld DINF=numeric_limits<ld>::infinity();
const ld EPS=1e-9;
const ld PI=3.1415926535897932;
const ll dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
const ll dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...) name
/*繰り返し*/
#define rep1(n) for(ll i=0;i<n;++i)//n回repeat
#define rep2(i,n) for(ll i=0;i<n;++i)//n回repeat（変数指定）
#define rep3(i,a,b) for(ll i=a;i<b;++i)//a-bまでrepeat
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)//a-bまで公差cでrepeat（等差数列で使えそう）
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)//repeatまとめ
#define rrep1(n) for(ll i=(n);i--;)
#define rrep2(i,n) for(ll i=(n);i--;)
#define rrep3(i,a,b) for(ll i=(b);i-->(a);)
#define rrep4(i,a,b,c) for(ll i=a+(b-a-1)/c*c;i>=a;i-=c)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)//逆repeatまとめ
#define each1(i,a) for(auto&& i:a)
#define each2(x,y,a) for(auto&& [x,y]:a)
#define each3(x,y,z,a) for(auto&& [x,y,z]:a)
#define each(...) overload4(__VA_ARGS__,each3,each2,each1)(__VA_ARGS__)//配列の各要素の読み出し
#define all1(i) begin(i),end(i)
#define all2(i,a) begin(i),begin(i)+a
#define all3(i,a,b) begin(i)+a,begin(i)+b
#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)//vectorの始めと終わりの読み取り
#define rall1(i) (i).rbegin(),(i).rend()
#define rall2(i,k) (i).rbegin(),(i).rbegin()+k
#define rall3(i,a,b) (i).rbegin()+a,(i).rbegin()+b
#define rall(...) overload3(__VA_ARGS__,rall3,rall2,rall1)(__VA_ARGS__)//逆イテレータの取得(rbegin：末尾,rend：頭）
#define sum(...) accumulate(all(__VA_ARGS__),0LL)//vectorの合計(int形で受け付けてしまうので，小数で扱いたい場合はdsumを使う)
#define dsum(...) accumulate(all(__VA_ARGS__),0.0L)//小数で扱う(long long doubleなど)
#define elif else if
#define unless(a) if(!(a))
#define mp make_pair
#define mt make_tuple
/*標準入力*/
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)//int型標準入力受付，以下LDまで同様
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
/*vector操作*/
#define Sort(a) sort(all(a))//昇順ソート
#define RSort(vec) sort(vec.begin(), vec.end(), greater<ll>())//降順ソート
#define Rev(a) reverse(all(a))//逆順
#define Uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))
#define vec(type,name,...) vector<type> name(__VA_ARGS__)//type型vectorの定義
#define VEC(type,name,size) vector<type> name(size);in(name)//type型vector(size指定)標準入力受付
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)
#define IV(type,name,size) vector<pair<int, int>> name;for (int i = 0; i < size; i++) {int a_i;cin >> a_i; name.emplace_back(a_i,i);}//Indexつきvector（pair型Vector,(data,index)）
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }
inline ll popcnt(ull a){ return __builtin_popcountll(a); }
ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
template<class T, class U> bool chmin(T& a, const U& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T, class U> bool chmax(T& a, const U& b){ if(a < b){ a = b; return 1; } return 0; }
vector<ll> iota(ll n){ vector<ll> a(n); iota(a.begin(), a.end(), 0); return a; }//0~n-1まで順に入れられたvectorを生成
vector<pll> factor(ull x){ vector<pll> ans; for(ull i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }//xの素因数分解{素因数，何個あるか}のvectorを返す
map<ll,ll> factor_map(ull x){ map<ll,ll> ans; for(ull i = 2; i * i <= x; i++) if(x % i == 0){ ans[i] = 1; while((x /= i) % i == 0) ans[i]++; } if(x != 1) ans[x] = 1; return ans; }//素因数分解mapVer.キー：素因数，要素＝その個数
vector<ll> divisor(ull x){ vector<ll> ans; for(ull i = 1; i * i <= x; i++) if(x % i == 0) ans.push_back(i); rrep(ans.size() - (ans.back() * ans.back() == x)) ans.push_back(x / ans[i]); return ans; }//約数が昇順に格納されたvectorを返す
template<class T> unordered_map<T, ll> press(vector<T>& a){ auto b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); unordered_map<T, ll> ans; rep(b.size()) ans[b[i]] = i; each(i, a) i = ans[i]; return ans; }//圧縮　aの各要素をa内の要素で見た時に昇順で何番目だったかの情報に置き換える，{要素，何番目}を表すunordered_mapを返す
template<class T> map<T, ll> press_map(vector<T>& a){ auto b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); map<T, ll> ans; rep(b.size()) ans[b[i]] = i; each(i, a) i = ans[i]; return ans; }//圧縮mapVer.
int scan(){ return getchar(); }
void scan(int& a){ scanf("%d", &a); }
void scan(unsigned& a){ scanf("%u", &a); }
void scan(long& a){ scanf("%ld", &a); }
void scan(long long& a){ scanf("%lld", &a); }
void scan(unsigned long long& a){ scanf("%llu", &a); }
void scan(char& a){ do{ a = getchar(); }while(a == ' ' || a == '\n'); }
void scan(float& a){ scanf("%f", &a); }
void scan(double& a){ scanf("%lf", &a); }
void scan(long double& a){ scanf("%Lf", &a); }
void scan(vector<bool>& a){ for(unsigned i = 0; i < a.size(); i++){ int b; scan(b); a[i] = b; } }
void scan(char a[]){ scanf("%s", a); }
void scan(string& a){ cin >> a; }
template<class T> void scan(vector<T>&);
template<class T, size_t size> void scan(array<T, size>&);
template<class T, class L> void scan(pair<T, L>&);
template<class T, size_t size> void scan(T(&)[size]);
template<class T> void scan(vector<T>& a){ for(auto&& i : a) scan(i); }
template<class T> void scan(deque<T>& a){ for(auto&& i : a) scan(i); }
template<class T, size_t size> void scan(array<T, size>& a){ for(auto&& i : a) scan(i); }
template<class T, class L> void scan(pair<T, L>& p){ scan(p.first); scan(p.second); }
template<class T, size_t size> void scan(T (&a)[size]){ for(auto&& i : a) scan(i); }
template<class T> void scan(T& a){ cin >> a; }
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){ scan(head); in(tail...); }
void print(){ putchar(' '); }
void print(bool a){ printf("%d", a); }
void print(int a){ printf("%d", a); }
void print(unsigned a){ printf("%u", a); }
void print(long a){ printf("%ld", a); }
void print(long long a){ printf("%lld", a); }
void print(unsigned long long a){ printf("%llu", a); }
void print(char a){ printf("%c", a); }
void print(char a[]){ printf("%s", a); }
void print(const char a[]){ printf("%s", a); }
void print(float a){ printf("%.15f", a); }
void print(double a){ printf("%.15f", a); }
void print(long double a){ printf("%.15Lf", a); }
void print(const string& a){ for(auto&& i : a) print(i); }
template<class T> void print(const vector<T>&);
template<class T, size_t size> void print(const array<T, size>&);
template<class T, class L> void print(const pair<T, L>& p);
template<class T, size_t size> void print(const T (&)[size]);
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T> void print(const deque<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T, size_t size> void print(const array<T, size>& a){ print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T, class L> void print(const pair<T, L>& p){ print(p.first); putchar(' '); print(p.second); }
template<class T, size_t size> void print(const T (&a)[size]){ print(a[0]); for(auto i = a; ++i != end(a); ){ putchar(' '); print(*i); } }
template<class T> void print(const T& a){ cout << a; }
int out(){ putchar('\n'); return 0; }
template<class T> int out(const T& t){ print(t); putchar('\n'); return 0; }//cout<<t<<endl
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
#ifdef DEBUG
inline ll __lg(ull __n){ return sizeof(ull) * __CHAR_BIT__  - 1 - __builtin_clzll(__n); }
#define debug(...) { print(#__VA_ARGS__); print(":"); out(__VA_ARGS__); }
#else
#define debug(...) void(0)
#endif
/*判定出力*/
int first(bool i = true){ return out(i?"first":"second"); }//iがfirstか判断，以下同様
int yes(bool i = true){ return out(i?"yes":"no"); }
int Yes(bool i = true){ return out(i?"Yes":"No"); }
int No(){ return out("No"); }
int YES(bool i = true){ return out(i?"YES":"NO"); }
int NO(){ return out("NO"); }
int Yay(bool i = true){ return out(i?"Yay!":":("); }
int possible(bool i = true){ return out(i?"possible":"impossible"); }
int Possible(bool i = true){ return out(i?"Possible":"Impossible"); }
int POSSIBLE(bool i = true){ return out(i?"POSSIBLE":"IMPOSSIBLE"); }
void Case(ll i){ printf("Case #%lld: ", i); }
/*vector探索*/
#define bSearch(v,k) binary_search(all(v),k)//ソートされた配列vの中の要素にkがあるか(boolean)
#define lowB(v,k) lower_bound(all(v),k)//ソートされた配列vの中の要素のうちk以上かつ最小のイテレータ
#define DLbetB(v,k) lowB(v,k)-v.begin()//先頭からの距離
#define DLbetE(v,k) v.end()-lowB(v,k)//末尾からの距離
#define uppB(v,k) upper_bound(all(v),k)//ソートされた配列vの中の要素のうちkより大きいかつ最小のイテレータ
#define DUbetB(v,k) uppB(v,k)-v.begin()//先頭からの距離
#define DUbetE(v,k) v.end()-uppB(v,k)//末尾からの距離
#define Cnt(v,k) count(all(v),k)//配列vの中で要素kが何個あるかを返す(size_t)
#define CntIf(v,l) count_if(all(v),l)//配列vの中で条件式(lambda式)を満たす個数を返す(ex.int num = count_if(v.begin(), v.end(), [](int i){return i % 3 == 0;});)
#define Sort2D(myVec,i) sort(myVec.begin(),myVec.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[i] < beta[i];});//i列めでソート
/*最大公約数*/
template <class T>
T vgcd(T m, T n) {
  return gcd(m, n);
}

template <class T, class... Args>
T vgcd(T a, Args... args) {
  return vgcd(a, vgcd(args...));
}
/*あまり（強制的に正の余りを出力）*/
void mod(ll &n,ll p){
  n%=p;
  if(n<0)n+=p;
}
ll rtmod(ll n,ll p){
  mod(n,p);
  return n;
}
/*逆元　あまりの割り算をするときにこいつをかける(a/b→a*modinv(b))*/
// mod. m での a の逆元 a^{-1} を計算する
ll modinv(ll a,ll m){
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
/*階乗*/
ll facctorialMethod(ll k){
    ll sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i;
        //sum%=MOD;//あまりを出力せよ問題の時はこれもやる
    }
    return sum;
}
ll fac2(ll k,ll a,ll p){
    ll sum = 1;
    for (ll i = k; i > k-a; --i)
    {
        sum *= i;
        sum%=p;//あまりを出力せよ問題の時はこれもやる
    }
    return sum;
}
/*組み合わせnCk*/
ll comb(const ll N,const ll K){
  vector<vector<long long int> > v(N+1,vector<long long int>(N+1,0));
  for(int i = 0;i <v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(int k = 1;k <v.size();k++){
    for(int j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }
  return v[N][K];
}
ll modcomb(ll n,ll k,ll p){
  ll c=fac2(n,k,p);
  c*=modinv(fac2(k,k,p),p);
  mod(c,p);
  return c;
}
/*ダブリング*/
/*
参考：http://satanic0258.hatenablog.com/entry/2017/02/23/222647

使える場所：1回遷移した先が明確にわかる時

目的：
・ある数XのQ乗を求める
・根付き木において、ある頂点vのQ個上の親を知る
・ある地点からQ回進んだ先を求める
*/
//int N; // 全体の要素数
//int Q;//試行回数
ll doubling(const ll N,const ll Q,vector<ll> &a){//cin>>N>>Q;//標準入力から要素数と試行回数を受け取る場合
ll LOG_Q = floor(log2(Q))+1;

// next[k][i]で、i番目の要素の「2^k個次の要素」を指す
// (なお、i番目の要素に対して「2^k個次の要素」が存在しないとき、
//  next[k][i]が指し示す要素番号を-1とします)
std::vector<std::vector<ll>> next(LOG_Q + 1, std::vector<ll>(N));
//ll a[N];//各要素の次の行き先

// next[0]を計算
for (int i = 0; i < N; ++i){
    next[0][i] = a[i];
}

// nextを計算
for (ll k = 0; k < LOG_Q; ++k){
    for (int i = 0; i < N; ++i){
        if (next[k][i] == -1) {
            // 2^k個次に要素が無い時、当然2^(k+1)個次にも要素はありません
            next[k + 1][i] = -1;
        }
        else {
            // 「2^k個次の要素」の2^k個次の要素は、2^(k+1)個次の要素です
            next[k + 1][i] = next[k][next[k][i]];
        }
    }
}

// ----ここまで準備----

// p番目の要素の「Q個次の要素」を求めることを考えます
ll p=0;
for (ll k = LOG_Q - 1; k >= 0; --k){
    if (p == -1) {
        // pがすでに存在しない要素を指していたら、
        // それ以降で存在する要素を指すことはないためループを抜けます
        break;
    }
    if ((Q >> k) & 1) {//ex(Q=5)5=101(2)であり，2^2+2^0回進むことを表す
        // Qを二進展開した際、k番目のビットが立っていたら、
        // pの位置を2^kだけ次にずらします
        p = next[k][p];
    }
}
return p;//ここでのpが最終的な答えになる
}
/*素数判定*/
bool IsPrime(ll num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}


/*ページのソースを表示->command+F->問題文　で問題文コピペする

*/
/*
0~n-1までの順列の出力
rep(n)v.push_back(i);
do{}while(next_permutation(all(v)));
*/
//ceil()//切り上げ　ll(ceil((ld)n/(ld)x))=(n+x-1)/x（整数除算）なのでそっちがいいかも
//floor()//切り捨て
//round()//四捨五入
//deque<ll> deq;//両端キュー使う，先頭と末尾へのアクセスが早い
//using std::map;
//map<string,ll>memo;//<キー，その要素＞，キーの検索が早い，キーは昇順にソートされる

template<class T>
T extgcd(T a, T b, T& x, T& y) {
    for (T u=y=1,v=x=0; a; ) {
        T q = b / a;
        swap(x -= q*u, u);
        swap(y -= q*v, v);
        swap(b -= q*a, a);
    }
    return b;
}

inline long long mod_pow(long long x, long long e, long long mod) {
    long long v = 1LL;
    for ( ; e; e>>=1) {
        if (e & 1) v = (v * x) % mod;
        x = (x * x) % mod;
    }
    return v;
}

inline long long mod_inv(long long a, long long mod) {
    // return mod_pow(a, mod-2, mod); // slower
    long long x, y;
    extgcd(a, mod, x, y);
    return (mod + x % mod) % mod;
}

long long _garner(vector<long long>& xs, vector<long long>& mods) {
    int M = xs.size();

    vector<long long> coeffs(M, 1), constants(M, 0);

    for (int i=0; i<M-1; ++i) {
        long long mod_i = mods[i];
        // coffs[i] * v + constants[i] == mr[i].val (mod mr[i].first) を解く
        long long v = (xs[i] - constants[i] + mod_i) % mod_i;
        v = (v * mod_inv(coeffs[i], mod_i)) % mod_i;

        for (int j=i+1; j<M; j++) {
            long long mod_j = mods[j];
            constants[j] = (constants[j] + coeffs[j] * v) % mod_j;
            coeffs[j] = (coeffs[j] * mod_i) % mod_j;
        }
    }

    return constants.back();
}

template<typename T>
inline void bit_reverse(vector<T>& a) {
    int n = a.size();
    int i = 0;
    for (int j=1; j<n-1; ++j) {
        for (int k = n >> 1; k >(i ^= k); k >>= 1);
        if (j < i) swap(a[i], a[j]);
    }
}


template<long long mod, long long primitive_root>
class NTT {
public:
    long long get_mod() { return mod; }

    void _ntt(vector<long long>& a, int sign) {
        const int n = a.size();
        assert((n ^ (n&-n)) == 0); //n = 2^k

        const long long g = primitive_root; // g is primitive root of mod

        long long tmp = (mod - 1) * mod_inv(n, mod) % mod; // -1/n
        long long h = mod_pow(g, tmp, mod); // ^n√g
        if (sign == -1) h = mod_inv(h, mod);

        bit_reverse(a);

        for (int m=1; m<n; m<<=1) {
            const int m2 = 2 * m;
            long long _base = mod_pow(h, n/m2, mod);
            long long _w = 1;
            for (int x=0; x<m; ++x) {
                for (int s=x; s<n; s+=m2) {
                    long long u = a[s];
                    long long d = (a[s + m] * _w) % mod;
                    a[s] = (u+d) % mod;
                    a[s+m] = (u-d+mod) % mod;
                }
                _w = (_w * _base) % mod;
            }
        }
    }
    void ntt(vector<long long>& input) {
        _ntt(input, 1);
    }
    void intt(vector<long long>& input) {
        _ntt(input, -1);

        const long long n_inv = mod_inv(input.size(), mod);
        for (auto &x : input) x = (x * n_inv) % mod;
    }

    // 畳み込み演算を行う
    vector<long long> convolution(const vector<long long>& a, const vector<long long>& b){
        int result_size = a.size() + b.size() - 1;
        int n = 1; while (n < result_size) n <<= 1;

        vector<long long> _a = a, _b = b;
        _a.resize(n, 0);
        _b.resize(n, 0);

        ntt(_a);
        ntt(_b);
        for (int i=0; i<n; ++i) _a[i] = (_a[i] * _b[i]) % mod;
        intt(_a);

        _a.resize(result_size);
        return _a;
    }
};


vector<long long> convolution_ntt(vector<long long>& a, vector<long long>& b, long long mod=1224736769LL) {
    for (auto &x : a) x %= mod;
    for (auto &x : b) x %= mod;

    ll maxval = max(a.size(), b.size()) * *max_element(a.begin(), a.end()) * *max_element(b.begin(), b.end());
    if (maxval < 1224736769) {
    	NTT<1224736769, 3> ntt3;
        return ntt3.convolution(a, b);
    }

    NTT<167772161, 3> ntt1;
    NTT<469762049, 3> ntt2;
    NTT<1224736769, 3> ntt3;

    vector<long long> x1 = ntt1.convolution(a, b);
    vector<long long> x2 = ntt2.convolution(a, b);
    vector<long long> x3 = ntt3.convolution(a, b);

    vector<long long> ret(x1.size());
    vector<long long> mods { 167772161, 469762049, 1224736769, mod };
    for (int i=0; i<x1.size(); ++i) {
        vector<long long> xs { x1[i], x2[i], x3[i], 0 };
        ret[i] = _garner(xs, mods);
    }

    return ret;
}

signed main(){
    /*以下コード*/
    LL(n);
    ll ans=0,sm=0;
    rep(n){
      LL(ai);
      sm+=ai;
      ans+=rtmod(ai*ai,MOD);
      mod(sm,MOD);
      mod(ans,MOD);
    }
    ans=-ans;
    ans+=rtmod(sm*sm,MOD);
    ans*=modinv(2,MOD);
    mod(ans,MOD);
    out(ans);
}
