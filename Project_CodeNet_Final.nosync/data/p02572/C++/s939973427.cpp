#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
#include <stdio.h>
#include <numeric>
#include <cmath>
#include <limits>
#include <bitset> 
#include <iterator> 
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <deque>
#include <regex>
#include <list>
#include <unordered_set>
#include <assert.h>
#include <functional>
#include <sstream>
#include <stack>
#define rep(i,n) for(ll i=0;i<(n); ++i)
#define rep1(i,n) for(ll i=1;i<=(n); ++i)
#define per(i,n) for(ll i=n-1;i>=0; --i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
#define _GLIBCXX_DEBUG
using namespace std;

//省略表現
const long long INF = 1LL << 60;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using GraphEdge = vector <vector<P>>;
using Graph = vector <vector<ll>>;
const int mod = 1000000007;
long double eps = 0.01;
constexpr double deps = numeric_limits<double>::epsilon();
//実行時間高速化
struct __INIT { __INIT() { cin.tie(nullptr); ios::sync_with_stdio(false); } } __init;
//入出力省略用関数。
inline void ldout(double d) { cout << fixed << setprecision(20) << d << endl; }
inline void out(ll n) { cout << fixed << setprecision(0) << n << endl; }
//辺にコストを持たせる構造体
/**
struct Edge{
    ll to;
    ll cost;
    Edge(ll t, ll c) : to(t), cost(c) {}
};
*/
//剰余計算
struct mint {
    ll x; // typedef long long ll;
    mint(ll x = 0) :x((x% mod + mod) % mod) {}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const {
        return pow(mod - 2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }
};
//unorderd_mapのキーにpairを使えるようにするための構造体
struct HashPair {

    //注意 constがいる
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {

        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        size_t seed = 0;
        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};
//最大値、最小値用のdp用の関数
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//固定長配列の大きさ（dp用）
template<typename TYPE, size_t SIZE>
size_t array_length(const TYPE(&)[SIZE])
{
    return SIZE;
}
//テンプレ出力
void out(bool b, string ok, string no) {
    cout << (b ? ok : no) << endl;
}

//二分探索のときは、begin().end()の処理を忘れないこと。
//未満のイテレーターを求める。
auto downer_bound(vector<ll>& v, ll n) {
    return (--lower_bound(All(v), n));
}

//以下のイテレーターを求める。
auto higher_bound(vector<ll>& v, ll n) {
    return (--upper_bound(All(v), n));
}

//'0'~'9を数値に変換する
ll stochr(char c) {
    return (ll)c - '0';
}
//logABを計算する。
long double logAB(ll a, ll b) {
    return log(b) / log(a);
}
//整数ceil（誤差問題を防ぐ）
ll Nceil(ll a, ll b) {
    return (a + b - 1) / b;
}
//累積和系ライブラリ
struct cul {
    vector<ll>culSum;

    //値渡し(&なし）だとvectorの受け取りにサイズ分かかるので、必ず参照渡しである&をつける必要がある。
    cul(vector<ll>& v) :culSum(v.size() + 1, 0) {
        rep(i, v.size()) {
            culSum[i + 1] = culSum[i]%mod + v[i]%mod;
            culSum[i + 1] %= mod;
        }
    }
    //累積和の配列自体を返す。
    vector<ll> culAll() {
        return culSum;
    }

    //部分和。
    ll partialSum(ll l, ll r) {
        l++; r++;//0-indexedに直す
        return culSum[r] - culSum[l - 1];
    }
};
//いもす法(O(N));
vector<ll> imos(vector<ll>& v, vector<tuple<ll, ll, ll>>& lra) {
    ll n = v.size();
    vector<ll>imosV(n + 1, 0);
    rep(i, lra.size()) {
        ll& l = get<0>(lra[i]);
        ll& r = get<1>(lra[i]);
        ll& a = get<2>(lra[i]);
        if (l == -INF) {
            imosV[min(n, r)] += a;
        }
        else {
            imosV[max(0LL, l)] += a;
            imosV[min(n, r + 1)] -= a;
        }
    }
    cul imosCul(imosV);
    vector<ll> imosCulSum = imosCul.culAll();
    //既にある配列に足す。
    rep(i, n) {
        v[i] += imosCulSum[i + 1];
        //min(v[i],n);
    }
    return v;
}
//組み合わせ(剰余付き)
//combination c(n)で初期化する必要がある。（nはCの左側の数）
struct combination {
    vector<mint> fact, ifact;
    combination(int n) :fact(n + 1), ifact(n + 1) {
        assert(n < mod);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
    }
    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
};
//桁取得
ll getDigit(ll n) {
    ll cnt = 0;
    while (n != 0) {
        n /= 10;
        cnt++;
    }
    return cnt;
}
//素数判定（O（sqrt(n)））
//繰り返す数がn/sqrt(n)回以下なら、こっちの素数判定の方が速いはず（k*sqrt(n)<=n）
bool isPrime(ll n) {
    if (n == 1)return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0)return false;
    }
    return true;
}
unordered_map<ll, vector<pair<ll, ll>>>mp;
//素因数分解（O(sqrt(N))）
//素因数分解したい値が10^8以上ならこっちを使う
vector<pair<ll, ll>> factorize(ll n) {
    ll tmpNum = n;
    vector<pair<ll, ll>> res, tmp;
    if (!mp[n].empty()) {
        return mp[n];
    }
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i) continue;
        else {
            res.emplace_back(i, 0);
            if (tmpNum == 20) {
                ll x = 20;
            }
            while (n % i == 0) {
                if (tmpNum != n)break;
                n /= i;
                res.back().second++;
                if (!mp[n].empty()) {
                    tmp = factorize(n);
                    if (n % i == 0) {
                        for (ll k = 0; k < tmp.size(); k++) {
                            if (tmp[k].first == i) {
                                tmp[k].second++;
                            }
                        }
                    }
                    else {
                        tmp.emplace_back(i, 1);
                    }
                    mp[tmpNum] = tmp;
                    break;
                }
            }
        }
    }
    if (mp[tmpNum].empty()) {
        if (n != 1) res.emplace_back(n, 1);
        mp[tmpNum] = res;
        return res;
    }
    return mp[tmpNum];
}
//エラストテネスの篩（O(NloglogN))
struct Sieve {
    ll n;
    vector <ll> f, primes;
    Sieve(ll n = 1) :n(n), f(n + 1) {
        f[0] = f[1] = -1;
        for (ll i = 2; i <= n; ++i) {
            if (f[i]) continue;
            primes.push_back(i);
            f[i] = i;
            for (ll j = i * i; j <= n; j += i) {
                if (!f[j]) f[j] = i;
            }
        }
    }

    //素数判定
    bool isPrime(ll x) { return f[x] == x; }
    vector<ll> factorList(ll x) {
        vector<ll> res;
        while (x != 1) {
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }

    //素因数分解
    vector<P> factor(ll x) {
        vector<ll> fl = factorList(x);
        if (fl.size() == 0) return {};
        vector<P> res(1, P(fl[0], 0));
        for (ll p : fl) {
            if (res.back().first == p) {
                res.back().second++;
            }
            else {
                res.emplace_back(p, 1);
            }
        }
        return res;
    }
};
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
//ペア比較順序
typedef pair<ll, ll> pair_t;
bool PSecComp(const pair_t& a, const pair_t& b) {
    if (a.second == b.second)return  a.first > b.first;
    else {
        return a.second > b.second;
    }
}
//UnionFind木（O（α（ｎ）））アッカーマン関数の逆数
struct UnionFind {
    vector<ll>d;
    UnionFind(ll n) :d(n, -1) {};
    ll find(ll x) {
        if (d[x] < 0)return x;
        else return d[x] = find(d[x]);
    }
    bool unite(ll x, ll y) {
        ll px = find(x), py = find(y);
        if (px == py)return false;//MSTのクラスカル法で使うらしい
        if (-d[px] < -d[py])swap(px, py);//(小さい木を大きい木に張る（マージテク））
        d[px] += d[py];
        d[py] = px;//yの親をxに張り替えている
        return true;
    }
    bool same(ll x, ll y) {
        return find(x) == find(y);
    }
    ll size(ll x) {
        return -d[find(x)];
    }
};
inline void debugVi(vector<ll>& v) { for (auto x : v)cout << x << " "; }
inline void debugXY(vector<vector<char>>& tmpXY) {
    rep(i, tmpXY.size()) {
        rep(k, tmpXY[i].size()) {
            cout << tmpXY[i][k];
        }
        cout << endl;
    }
    cout << endl;
}
vector<string>ans;
void dfs(string v, ll d) {
    if (d >= 6)return;
    ans.push_back(v);
    for (ll i = 0; i < 6; i++) {
        if (v.find(to_string(i)) != string::npos)continue;
        else dfs(v + to_string(i), d + 1);
    }
}
vector<ll>memo(1000, -INF);
ll f(ll v, bitset<1000> tmpbit, ll ver) {
    if (tmpbit.count() == 0) {
        return ver;
    }
    ll tmpNum = v % tmpbit.count();
    bitset<1000> tmpbit2(tmpNum);
    if (memo[tmpNum] != -INF) {
        //return memo[tmpNum];
    }

    return f(tmpNum, tmpbit2, ver + 1);

}
ll f2(bitset<1000> tmpbit) {
    ll sum = 0;
    for (ll i = tmpbit.size() - 1; i >= 0; i--) {
        if (tmpbit[i] == 1) {
            sum += pow(2, i);
        }
    }
    return sum;
}
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    vector<mint>am(n);
    /*
    for (ll i = 0; i < 2*1e5; i++) {
        a.push_back(1e9);
    }
    */
    
    rep(i, n)cin >> a[i];
    rep(i, n)am[i] = a[i];
    mint asum = 0;
    rep(i, n) {
        asum += am[i];
    }
    mint sum = 0;
    asum -= a[0];
    for (ll i = 0;i < n; i++) {
        sum += am[i] * asum;
        if(asum.x != 0)asum -= a[i+1];
        //cout << asum << endl;
    }
    cout << sum.x << endl;
}

