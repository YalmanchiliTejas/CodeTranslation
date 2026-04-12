#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Pld = pair<ld, ld>;
using Vec = vector<ll>;
using VecP = vector<P>;
using VecB = vector<bool>;
using VecC = vector<char>;
using VecD = vector<ld>;
using VecS = vector<string>;
template <class T>
using Vec2 = vector<vector<T>>;
#define REP(i, m, n) for(ll i = (m); i < (n); ++i)
#define REPN(i, m, n) for(ll i = (m); i <= (n); ++i)
#define REPR(i, m, n) for(ll i = (m)-1; i >= (n); --i)
#define REPNR(i, m, n) for(ll i = (m); i >= (n); --i)
#define rep(i, n) REP(i, 0, n)
#define repn(i, n) REPN(i, 1, n)
#define repr(i, n) REPR(i, n, 0)
#define repnr(i, n) REPNR(i, n, 1)
#define all(s) (s).begin(), (s).end()
#define pb push_back
#define fs first
#define sc second
template <class T1, class T2>
bool chmax(T1 &a, const T2 b){if(a < b){a = b; return true;} return false;}
template <class T1, class T2>
bool chmin(T1 &a, const T2 b){if(a > b){a = b; return true;} return false;}
ll pow2(const int n){return (1LL << n);}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (const T &i : v) os << i << ' ';
    return os;
}
void co() { cout << '\n'; }
template <class Head, class... Tail>
void co(Head&& head, Tail&&... tail) {
    cout << head << ' ';
    co(forward<Tail>(tail)...);
}
void ce() { cerr << '\n'; }
template <class Head, class... Tail>
void ce(Head&& head, Tail&&... tail) {
    cerr << head << ' ';
    ce(forward<Tail>(tail)...);
}
void sonic(){ios::sync_with_stdio(false); cin.tie(0);}
void setp(const int n){cout << fixed << setprecision(n);}
constexpr int INF = 1000000001;
constexpr ll LINF = 1000000000000000001;
constexpr ll MOD = 1000000007;
constexpr ll MOD_N = 998244353;
constexpr ld EPS = 1e-11;
const double PI = acos(-1);

template <typename T>
struct BIT{
    ll N;
    vector<T> data;

    BIT(ll n){
        init(n);
    }

    void init(ll n){
        N = 1;
        while(N < n) N <<= 1;
        data.assign(N, 0);
    }

    void build(vector<T> v){
        init(N);
        for(int i = 0; i < v.size(); ++i){
            add(i, v[i]);
        }
    }

    void add(ll k, T x){
        ++k;
        while(k <= N){
            data[k] += x;
            k += k & -k;
        }
    }

    // [0, k)
    T sum(ll k){
        T res = 0;
        while(k){
            res += data[k];
            k -= k & -k;
        }
        return res;
    }

    // [a, b)
    T sum(ll a, ll b){return sum(b) - sum(a);}

    T at(ll k){return sum(k) - sum(k - 1);}

    
    T lower_bound(T k){
        ll l = 0, r = N;
        while(r - l > 1){
            ll m = (l + r) / 2;
            if(sum(m) >= k) r = m;
            else l = m;
        }
        return r;
    }
};

int main(void) {
    ll n, x, m;
    cin >> n >> x >> m;
    Vec memo(m, LINF);
    BIT<ll> bit(m);
    ll ans = 0, cnt = 0;
    while(cnt < n){
        x %= m;
        // ce(cnt, x, ans);
        if (x == 0) break;
        if(x == 1){
            ans += n - cnt;
            break;
        }
        if(memo[x] != LINF && n - cnt > 1e6){
            ans += bit.sum(memo[x], cnt) * ((n - cnt) / (cnt - memo[x]));
            cnt += ((n - cnt) / (cnt - memo[x])) * (cnt - memo[x]);
        }else{
            ans += x;
            memo[x] = cnt;
            bit.add(cnt, x);
            x *= x;
            cnt++;
        }
    }
    co(ans);

    return 0;
}