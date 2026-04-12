const int isDebugMode = 1;
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
struct edge{long long to,cost;};
const int inf = 1 << 27;
const long long INF = 1LL << 60;
const int COMBMAX = 1001001;
const long long MOD = 1000000007;
const long long dy[] = {-1, 0, 0, 1};
const long long dx[] = {0, -1, 1, 0};
string abc = "abcdefghijklmnopqrstuvwxyz";
#define rep(i,n) for(int i = 0; i < (n); ++i)
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
template<class T> void debug(T v){if(!isDebugMode) return; rep(i, v.size()) cout << v[i] << " " ; cout << endl;}
template<class T> void debug2(T v){if(!isDebugMode) return; rep(i, v.size()){rep(j, v[i].size()) cout << v[i][j] << " " ; cout << endl;}}
template<class T1, class T2> inline bool chmin(T1 &a, T2 b){if(a > b){a = b; return true;} return false;}
template<class T1, class T2> inline bool chmax(T1 &a, T2 b){if(a < b){a = b; return true;} return false;}
template<class T1, class T2> long long recgcd(T1 a, T2 b){return a % b ? recgcd(b , a % b) : b;}
bool valid(long long H, long long W, long long h, long long w) { return 0 <= h && h < H && 0 <= w && w < W; }

struct mint {
long long x;
    mint(long long x = 0):x((x % MOD + MOD) % MOD){}
    mint& operator += (const mint a) {if ((x += a.x) >= MOD) x -= MOD; return *this;}
    mint& operator -= (const mint a) {if ((x += MOD-a.x) >= MOD) x -= MOD; return *this;}
    mint& operator *= (const mint a) {(x *= a.x) %= MOD; return *this;}
    mint operator + (const mint a) const {mint res(*this); return res += a;}
    mint operator - (const mint a) const {mint res(*this); return res -= a;}
    mint operator * (const mint a) const {mint res(*this); return res *= a;}
    mint pow(long long t) const {if (!t) return 1; mint a = pow(t >> 1); a *= a; if (t&1) a *= *this; return a;}
    mint inv() const {return pow(MOD - 2);}
    mint& operator /= (const mint a) {return (*this) *= a.inv();}
    mint operator / (const mint a) const {mint res(*this); return res /= a;}
};

class combination {
    public:
    vector<mint> fact, ifact;
    combination(int n):fact(n + 1), ifact(n + 1) {
        assert(n < MOD);
        fact[0] = 1;
        for(int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for(int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
    }
    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        if (COMBMAX < n){
            mint ret = 1;
            for(long long i = 1; i <= k; i++){
                ret *= (n - i + 1);
                ret /= i;
            }
            return ret;
        }
        return fact[n] * ifact[k] * ifact[n - k];
    }

    mint multi(long long n, long long sum, long long l, long long r){
        long long m = r - l + 1;
        long long t = sum - n * (l - 1);
        mint ans = 0;
        for(long long k = 0; k <= (t - n) / m; k++){
            long long sign = k % 2 == 0 ? 1 : -1;
            mint temp = this->operator() (n, k);
            temp *= this->operator() (n + (t - n - m * k - 1), t - n - m * k);
            temp *= sign;
            ans += temp;
        }
        return ans;
    }
} com(COMBMAX);

int main(){
    ll N; cin >> N;
    vector<mint> a(N);
    mint sum = 0;
    rep(i, N){
        ll n; cin >> n;
        a[i] = n;  
        sum += a[i];
    }
    mint ans = 0;
    rep(i, N) ans += a[i] * (sum - a[i]);
    ans /= 2;
    pt(ans.x);
    return 0;
}