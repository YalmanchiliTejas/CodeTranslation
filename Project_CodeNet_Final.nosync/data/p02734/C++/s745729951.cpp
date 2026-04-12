#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

const ll MOD = 998244353;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define endl    "\n"
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC
#define verify(x) if(x >= MOD) x -= MOD;

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int nax = 3005;
ll n,s, arr[nax], pref[nax][nax], dp[nax][nax]; // dp[i][j] = sum of starting index of subseq ending at i with sum j

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n>>s;
    FOR(i, 1, n + 1) cin>>arr[i];
    memset(dp, 0, sizeof(dp));
    dp[1][arr[1]] = 1; pref[1][arr[1]] = 1;
    FOR(i, 2, n + 1) {
        FOR(j, 0, s + 1) {
            if(j < arr[i]) continue;
            ll sm = pref[i - 1][j - arr[i]];
            // FOR(k, 1, i) {
            //     sm += dp[k][j - arr[i]]; sm %= MOD;
            // }
            dp[i][j] = sm;
        }
        if(arr[i] <= s) {
            dp[i][arr[i]] += i; dp[i][arr[i]] %= MOD;
        }
        FOR(j, 0, s + 1) {
            pref[i][j] = dp[i][j] + pref[i - 1][j];
            pref[i][j] %= MOD;
        }
    }
    ll res = 0;
    FOR(i, 1, n + 1) {
        res += (dp[i][s] * 1LL * (n - i + 1))%MOD;
        res %= MOD;
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}