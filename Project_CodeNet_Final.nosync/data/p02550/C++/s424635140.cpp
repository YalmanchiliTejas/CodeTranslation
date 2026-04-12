constexpr bool isDebugMode = false;
int testcase = 1;
#include <bits/stdc++.h>
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
    using namespace atcoder;
#endif
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
struct edge{long long to,cost;};
const int inf = 1 << 27;
const long long INF = 1LL << 60;
const int COMBMAX = 1001001;
const long long MOD = 1000000007; //998244353;
const long long dy[] = {-1, 0, 0, 1};
const long long dx[] = {0, -1, 1, 0};
const string abc = "abcdefghijklmnopqrstuvwxyz";
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define eachdo(v, e) for (const auto &e : (v))
#define all(v) (v).begin(), (v).end()
#define lower_index(v, e) (long long)distance((v).begin(), lower_bound((v).begin(), (v).end(), e))
#define upper_index(v, e) (long long)distance((v).begin(), upper_bound((v).begin(), (v).end(), e))
long long mpow(long long a, long long n, long long mod = MOD){long long res = 1; while(n > 0){if(n & 1)res = res * a % mod; a = a * a % mod; n >>= 1;} return res;}
void pt(){cout << endl; return;}
template<class Head> void pt(Head&& head){cout << head; pt(); return;}
template<class Head, class... Tail> void pt(Head&& head, Tail&&... tail){cout << head << " "; pt(forward<Tail>(tail)...);}
void dpt(){if(!isDebugMode) return; cout << endl; return;}
template<class Head> void dpt(Head&& head){if(!isDebugMode) return; cout << head; pt(); return;}
template<class Head, class... Tail> void dpt(Head&& head, Tail&&... tail){if(!isDebugMode) return; cout << head << " "; pt(forward<Tail>(tail)...);}
template<class T> void enu(T v){rep(i, v.size()) cout << v[i] << " " ; cout << endl;}
template<class T> void enu2(T v){rep(i, v.size()){rep(j, v[i].size()) cout << v[i][j] << " " ; cout << endl;}}
template<class T> void debug(T v){if(!isDebugMode) return; rep(i, v.size()) cout << v[i] << " " ; cout << endl;}
template<class T> void debug2(T v){if(!isDebugMode) return; rep(i, v.size()){rep(j, v[i].size()) cout << v[i][j] << " " ; cout << endl;}}
template<class T1, class T2> inline bool chmin(T1 &a, T2 b){if(a > b){a = b; return true;} return false;}
template<class T1, class T2> inline bool chmax(T1 &a, T2 b){if(a < b){a = b; return true;} return false;}
template<class T1, class T2> long long recgcd(T1 a, T2 b){return a % b ? recgcd(b, a % b) : b;}
bool valid(long long H, long long W, long long h, long long w) { return 0 <= h && h < H && 0 <= w && w < W; }

void solve();

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    // cin >> testcase;
    while(testcase--) solve();
    return 0;
}

void solve(){
    ll N, X, M; cin >> N >> X >> M;
    vector<ll> ord;
    set<ll> aped;
    rep(i, N){
        if(aped.count(X)) break;
        aped.insert(X);
        if(X == 0) break;
        ord.push_back(X);
        X = ((X % M) * (X % M)) % M; 
    }
    ll ans = 0;
    // enu(ord);
    if(X == 0){
        ans = accumulate(all(ord), 0LL);
        pt(ans);
        return;
    }
    ll f = 0;
    for(ll i = 0; i < ord.size(); i++){
        if(ord[i] == X){
            f = i;
            break;
        }
    }

    ll lp = ord.size() - f;
    if(N - ord.size() > 0){
        ans += accumulate(all(ord), 0LL);
        N -= ord.size();
        ans += (N / lp) * accumulate(ord.begin() + f, ord.end(), 0LL);
        rep(i, N % lp) ans += ord[i + f];
        pt(ans);
    }else{
        pt(accumulate(all(ord), 0LL));
    }

}