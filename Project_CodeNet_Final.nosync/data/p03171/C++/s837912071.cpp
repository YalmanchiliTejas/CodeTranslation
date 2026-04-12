#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using Pld = pair<ld, ld>;
using Vec = vector<ll>;
using VecP = vector<pi>;
using VecB = vector<bool>;
using VecC = vector<char>;
using VecD = vector<ld>;
using VecS = vector<string>;
using Graph = vector<VecP>;
#define REP(i, m, n) for(ll (i) = (m); (i) < (n); ++(i))
#define REPR(i, m, n) for(ll (i) = (m); (i) > (n); --(i))
#define rep(i, n) REP(i, 0, n)
#define R cin>>
#define repr(i, n) REPR(i, n, 0)
#define all(s) (s).begin(), (s).end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define in(a) insert(a)
#define P(p) cout<<(p)<<endl;
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define SORT(a) sort((a).begin(), (a).end())
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
void sonic(){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);}
void setp(const ll n){cout << fixed << setprecision(n);}
const ll INF = 1e9+1;
const ll LINF = 1e18+1;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ld PI = acos(-1);
const ld EPS = 1e-11;
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
template<typename T> void co(T e){cout << e << "\n";}
template<typename T> void co(const vector<T>& v){for(const auto& e : v)
    { cout << e << " "; } cout << "\n";}
ll gcd(ll a, ll b) {
    if (a < b)swap(a, b);
    if (b == 0) return a;
    unsigned r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}
ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a * b / g;
}
bool prime(ll n) {
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n%i == 0)return false;
    }
    return n != 1;
}

Vec fac, finv;

ll PowMod(ll a, ll n){
    if(n == 1) return a;
    if(n%2 == 0) return PowMod(a*a%MOD, n/2);
    return a*PowMod(a*a%MOD, n/2)%MOD;
}

ll combi(ll n, ll k){
    if(k>n) return 0;
    return fac[n]*finv[k]%MOD*finv[n-k]%MOD;
}

int n;
vvl dp;
ll A[3000];
ll f(int l, int r) {
    if(l > r) return 0;
    if(dp[l][r] != INF) return dp[l][r];
    int flg = (l + n - r) % 2;
    if(flg) dp[l][r] = max(f(l + 1, r) + A[l], f(l, r - 1) + A[r]);
    else dp[l][r] = min(f(l + 1, r) - A[l], f(l, r - 1) - A[r]);
    return dp[l][r];
}


int main(){
    cin >> n;
    rep(i, n) cin >> A[i];
    dp.resize(n, vl(n, INF));
    co(f(0, n - 1));
}

