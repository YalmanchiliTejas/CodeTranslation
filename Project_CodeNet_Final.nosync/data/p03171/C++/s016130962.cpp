#pragma region Macros
#include <bits/stdc++.h>
#define SORT(x) sort((x).begin(), (x).end())
#define RSORT(x) sort((x).rbegin(), (x).rend())
#define ALL(x) (x).begin(), (x).end()
#define REV(x) reverse(ALL(x))
#define rep(i, n) for (ll i = 0; i < n; i++)
#define reps(i, m, n) for (ll i = m; i < n; i++)
#define repr(i, m, n) for (ll i = m; i >= n; i--)
#define SP << " " <<
#define INF2 1000000000000000037LL
#define INF  1000000007
#define lwb(x,n) distance(x.begin(),lower_bound(ALL(x),(n)))
#define upb(x,n) distance(x.begin(),upper_bound(ALL(x),(n)))
#define fora(i, ...) if(ll i = -1) for(__VA_ARGS__) if(i++, true)
#ifdef _MY_DEBUG
#define isdebug true
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,x,...) x
#define debug_1(x1) cout<<#x1<<": "<<x1<<endl
#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define de(...) CHOOSE((__VA_ARGS__,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)
#else
#define isdebug false
#define de(...)
#endif
using namespace std;
using ll = long long;
using ld = long double;
const ld PI = 3.141592653589793238462643;
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
template<class T = ll> using v = vector<T>;
template<class T = ll> using vv = vector<vector<T>>;
template<class T = ll> using vvv = vector<vector<vector<T>>>;
template<class T> bool maxi(T &a, const T &b){ if(a<b){a=b;return 1;}return 0;}
template<class T> bool mini(T &a, const T &b){ if(b<a){a=b;return 1;}return 0;}
template<class T> ll sumer(const T& a){ return accumulate(ALL(a),0LL); }
template<class T> ll miner(const T& a){ return *min_element(ALL(a)); }
template<class T> ll maxer(const T& a){ return *max_element(ALL(a)); }
template<class T> void UNIQUE(vector<T> &a){ SORT(a);a.erase(unique(ALL(a)),a.end());}
template<class T, class U> ostream &operator<<(ostream &os, const pair<T,U> &pe) { os << pe.first << " " << pe.second; return os;}
template<class T> ostream &operator<<(ostream &os, const v<T> &ve) { rep(i,ve.size()) os<< (i?" ":"")<<ve[i]; return os;}
ll topbit(ll a) { return a==0?-1:63-__builtin_clzll(a);}
ll botbit(ll a) { return a==0?64:__builtin_ctzll(a);}
ll popcount(ll a) { return __builtin_popcountll(a);}
#define dame do {cout<< retword <<"\n"; return;} while(false)
#pragma endregion
//--MODIFS---------------------------------
#pragma region Modifs
#define retword "-1"
#define MOD  1000000007
const ld EPS = 1e-9;
using P  = pair<ll,ll>;
using TP  = tuple<ll,ll,ll>;
#pragma endregion
//--GLOBAL---------------------------------
vv<> dp(3010,v<>(3010,-INF2));
//--MAIN-----------------------------------
void Main() {
    ll N;
    cin>>N;
    v<> A(N);
    rep(i,N) cin>>A[i];
    // そこから始めた人間が取る利得
    ll ans=0;
    rep(i,N+1) dp[i][i]=0;
    reps(len,1,N+1){
        rep(i,N-len+1){
            ll j=i+len;
            maxi(dp[i][j],-dp[i+1][j]+A[i]);
            maxi(dp[i][j],-dp[i][j-1]+A[j-1]);
        }
    }
    cout<< dp[0][N] <<"\n";
}
//--START----------------------------------
int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    // if(isdebug) {ifstream in("input.txt"); cin.rdbuf(in.rdbuf());}
    // if(isdebug) {ofstream out("output.txt"); cout.rdbuf(out.rdbuf());}
    cout << fixed << setprecision(15);
    // ll Qkai; cin>>Qkai; rep(QQ,Qkai) Main();
    Main();
}
//-----------------------------------------