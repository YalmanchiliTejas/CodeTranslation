#include <bits/stdc++.h>
 
// #include <iostream> // cout, endl, cin
// #include <string> // string, to_string, stoi
// #include <vector> // vector
// #include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
// #include <utility> // pair, make_pair
// #include <tuple> // tuple, make_tuple
// #include <cstdint> // int64_t, int*_t
// #include <cstdio> // printf
// #include <map> // map
// #include <queue> // queue, priority_queue
// #include <set> // set
// #include <stack> // stack
// #include <deque> // deque
// #include <unordered_map> // unordered_map
// #include <unordered_set> // unordered_set
// #include <bitset> // bitset
// #include <climits>
// #include <cmath>
// #include <iomanip>
// #include <functional>
// #include <numeric>
// #include <random>
 
using namespace std;
    
#define int long long
#define pb push_back
#define eb emplace_back
// #define F first
// #define S second
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define rep(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define ve vector
#define vi vector<int>
#define vp vector<pair<int,int>>
#define vvi vector<vector<int>>
#define UNIQUE(a) sort(all(a)), a.erase(unique(all(a)), a.end())
 
template<typename T> using pq = priority_queue<T,vector<T>,greater<T>>; 
using ll = long long;
ll INF = LLONG_MAX / 10 - 100;
int IINF = INT_MAX / 4;
ll mod = 1e9 + 7;
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
vector<ll> prime;

long double pi = 3.141592653589793238;
    
class fact {
public:
    long long fmod = 1e9+7;
    vector<long long> fac, finv, inv;
    fact (int n, long long Mod = 1e9+7) {
        fmod = Mod;
        fac = vector<long long>(n + 1, 0);
        finv = vector<long long>(n + 1, 0);
        inv = vector<long long>(n + 1, 0);
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1; 
        for (int i = 2; i < n + 1; i++) {
            fac[i] = fac[i-1] * i % fmod;
            inv[i] = mod - inv[mod%i] * (mod/i) % mod;
            finv[i] = finv[i-1] * inv[i] % mod;
        }
    }
    ll nCr(ll n, ll r) {if(n < r) return 0; return fac[n] * finv[r] % fmod * finv[n-r] % fmod;}
    ll POW(ll a, ll b) {ll c = 1; while (b > 0) {if (b & 1) {c = a * c%fmod;}a = a * a%fmod; b >>= 1;}return c;}
    inline int operator [] (int i) {return fac[i];}
    ll DeBuG(ll n, ll r);
};
    
void DEBUG(vector<int> a) {for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<endl;}
void EMP(int x) {cout<<"!!!"<<x<<"!!!"<<endl;}
ll GCD(ll a, ll b) {ll c; while (b != 0) {c = a % b; a = b; b = c;}return a;}
ll LCM(ll a, ll b) {return (a / GCD(a, b)) * (b / GCD(a, b)) * GCD(a, b);}
ll POW(ll a, ll b) {ll c = 1; while (b > 0) {if (b & 1) {c = a * c%mod;}a = a * a%mod; b >>= 1;}return c;}
void PRI(ll n) {bool a[n + 1]; for (int i = 0; i < n + 1; i++) {a[i] = 1;}for (int i = 2; i < n + 1; i++) {if (a[i]) {prime.pb(i); ll b = i; while (b <= n) {a[b] = 0; b += i;}}}}
template <typename T> T chmin(T& a, T b) {if(a>b)a=b;return a;}
template <typename T> T chmax(T& a, T b) {if(a<b)a=b;return b;}
bool isSqrt(ll a) {return pow(sqrt(a),2) == a ? 1 : 0;}
void YesNo(bool a) {if (a) cout << "Yes"; else cout << "No"; cout << endl;}
void yesno(bool a) {if (a) cout << "yes"; else cout << "no"; cout << endl;}
void YESNO(bool a) {if (a) cout << "YES"; else cout << "NO"; cout << endl;}
double dis(int x1, int x2, int y1, int y2) {
    return sqrt((double)abs(x1-x2)*(double)abs(x1-x2)+(double)abs(y1-y2)*(double)abs(y1-y2));
}
int ceili(int x, int y) {
    if (x % y == 0) return x / y;
    else return x / y + 1;
}


int dp[1010][1010];
fact fac(2000);

void solve() {
    int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
    dp[0][b+1] = 1;
    rep (i, n) {
        int sum = dp[i][b+1];
        for (int j = b; j >= a; j--) {
            dp[i][j] %= mod;
            int mul = 1;
            FOR (k, 1, d+1) {
                if (i + j * k > n) break;
                mul *= fac.nCr(n - i - j * (k - 1), j);
                mul %= mod;
                mul *= fac.inv[k];
                mul %= mod;
                if (c <= k) dp[i + j * k][j] += sum * mul % mod, dp[i + j * k][j] %= mod;
            }
            sum += dp[i][j];
            sum %= mod;
        }
    }
    int ans = 0;
    FOR (i, a, b+1) ans += dp[n][i];
    cout << ans % mod << endl;
}
 
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
