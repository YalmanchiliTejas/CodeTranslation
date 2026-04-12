#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define lb(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define ub(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
using Pair = pair<ll,pair<int,int>>;
#define pq priority_queue<Pair, vector<Pair>, greater<Pair>> 
const ll mod=1000000007;
//const ll mod=998244353;
const ld pi=acos(-1.0);
const ll INF = 1LL<<61;
template<class T>bool chmax(T &a, const T &b) { 
  if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) {
  if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる

//——————————————————modint———————————————————————————


#define MAX 2000000  // 階乗をいくつまで計算するか
 
class mint {
    ll val;
    static ll *invs, *facts, *finvs;
 
    // 階乗, 逆元, 階乗の逆元をMAXまで求める
    bool initMint() {
        invs[1] = 
        facts[0] = facts[1] =
        finvs[0] = finvs[1] = 1;
        for (int i=2; i<=MAX; i++) {
            invs[i]  = -invs[MOD % i] * (MOD / i) % MOD;
            facts[i] = facts[i - 1] * i % MOD;
            finvs[i] = finvs[i - 1] * invs[i] % MOD;
        }
        return true;
    }
 
public:
    static ll MOD; // modの元
 
    // 初期化 値を引数に与えなかった場合はval=0としておく
    mint(ll init = 0) : val(init) {
        static bool call_once = initMint(); // static変数の性質により一度だけ呼ばれる
        assert(call_once); // unusedの回避
        if (val < 0 || val >= MOD) val %= MOD;
        if (val < 0) val += MOD;   // 0以上であることを保証
    }
 
    inline ll toll() { return this->val; }
 
    // 代入
    void operator=(const mint &r) { this->val = r.val; }
    void operator=(const ll &r) { *this = mint(r); }
 
    // 足し算; 符号反転; 引き算
    mint operator+(const mint &r) {
        ll ans = this->val + r.val;
        if (ans >= MOD) ans -= MOD;
        return mint(ans);
    }
    mint operator-() {
        ll ans = MOD - this->val;
        return mint(ans);
    }
    mint operator-(const mint &r) {
        mint rr = r;
        return *this + (-rr);
    }
 
    //かけ算; 逆元; わり算
    mint operator*(const mint &r) {
        ll ans = this->val * r.val;
        return mint(ans);
    }
    mint inv() {
        assert(this->val != 0);
        if (this->val == 1) return mint(1);
 
        mint p, q = *this, m(0), n(1), r, c;
        p.val = MOD;
        while (q.val > MAX) {
            r = p.val % q.val;
            c = m.val - n.val * (p.val / q.val);
            p = q, q = r, m = n, n = c;
        }
        return n * invs[q.val];
    }
    mint operator/(const mint &r) { return *this * mint(r).inv(); }
    mint operator%(const mint &r) { return mint(this->val % r.val); }
 
    // ++ -- 前付きと後ろ付き
    void operator++() { ++this->val; }
    void operator++(int a) {
        a = 0;
        this->val++;
    }
    void operator--() { --this->val; }
    void operator--(int a) {
        a = 0;
        this->val--;
    }
 
    // 四則演算&代入
    void operator+=(const mint &r) { *this = *this + r; }
    void operator-=(const mint &r) { *this = *this - r; }
    void operator*=(const mint &r) { *this = *this * r; }
    void operator/=(const mint &r) { *this = *this / r; }
    void operator%=(const mint &r) { *this = *this % r; }
 
    // べき乗
    mint pow(long n) {
        if (n < 0)
            return inv().pow(-n);  // 逆元の-n乗
        else if (n == 0)
            return mint(1);
 
        mint half = pow(n / 2);
        if (n % 2)
            return *this * half * half;
        else
            return half * half;
    }
    mint pow(mint n) { return pow(n.val); }
 
    // 順列
    mint per(mint _k) {
        assert(this->val <= MAX);
        const ll n = this->val, k = _k.val;
        if (k < 0 || k > n) return 0;
        if (k == 0) return 1;
        if (k == n) return facts[n];
        return mint(facts[n]) * finvs[n - k];
    }

    // コンビネーション
    mint com(mint _k) {
        assert(this->val <= MAX);
        const ll n = this->val, k = _k.val;
        if (k < 0 || k > n) return 0;
        if (k == 0 || k == n) return 1;
        return mint(facts[n]) * finvs[k] * finvs[n - k];
    }
 
    // 階乗
    mint fact() { 
        assert(this->val <= MAX);
        return mint(facts[this->val]);
    }
 
    friend bool operator<(const mint &l, const mint &r) { return l.val < r.val; }
    friend bool operator>(const mint &l, const mint &r) { return l.val > r.val; }
    friend bool operator==(const mint &l, const mint &r) { return l.val == r.val; }
    friend bool operator!=(const mint &l, const mint &r) { return !(l.val == r.val); }
    friend bool operator<=(const mint &l, const mint &r) { return !(l.val > r.val); }
    friend bool operator>=(const mint &l, const mint &r) { return !(l.val < r.val); }
 
    friend ostream &operator<<(ostream &os, const mint &out) {
        os << out.val;
        return os;
    }
    friend istream &operator>>(istream &is, mint &in) {
        ll inl;
        is >> inl;
        in.val = inl % mint::MOD;
        return is;
    }
};
 
// べき乗
inline mint mpow(ll n, ll k) { return mint(n).pow(k); }
// 順列
inline mint mper(ll n, ll k) { return mint(n).per(k); }
// コンビネーション
inline mint mcom(ll n, ll k) { return mint(n).com(k); }
// 階乗
inline mint mfac(ll n) { return mint(n).fact(); }
 
// static変数
ll *mint::invs  = new ll[MAX+1];
ll *mint::facts = new ll[MAX+1];
ll *mint::finvs = new ll[MAX+1];
 
ll mint::MOD = (ll)1e9 + 7;

//—————————————————————————————————————————————————


//—————————————————————————————————————————————————

constexpr ll M = 1e9+7;
ll inv(ll a,ll p){
    return a==1?1:(p-p/a)*inv(p%a,p)%p;
}
ll com(ll n, int k){
	if(n<k) return 0;
	if(k==0) return 1;
	ll r = 1;
	for(int i=0;i<k;++i){
		r = r*(n-i)%M*inv(i+1,M)%M;
	}
	return r;
}

//—————————————————————————————————————————————————


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n,m,k;
  cin>>n>>m>>k;
  
  mint x=0,y=0,ans=0;

  repo(i,n){
    x+=i*(n-i);
  }
  x*=m*m;

  repo(i,m){
    y+=i*(m-i);
  }
  y*=n*n;
  
  ans=x+y;
  ans*=com(n*m-2,k-2);

  cout << ans << endl;
}