#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
/*----------------------------------ここからマクロ----------------------------------*/
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define vecin(a) rep(i,a.size())cin >> a[i]
#define vecout(a) rep(i,a.size()){cout << a[i];cout << (i == a.size() - 1 ? "\n":" ");}
#define overload4(_1,_2,_3,_4,name,...) name
#define rep1(n) for(int i=0;i<(int)n;++i)
#define rep2(i,n) for(int i=0;i<(int)n;++i)
#define rep3(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define rep4(i,a,b,c) for(int i=(int)a;i<(int)b;i+=(int)c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(n) for(int i=n-1;i>=0;i--)
#define rrep2(i,n) for(int i=n-1;i>=0;i--)
#define rrep3(i,a,b) for(int i=a-1;i>=b;i--)
#define rrep4(i,a,b,c) for(int i=a-1;i>=b;i-=c)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define mp make_pair
#define debug(x) cerr << #x << ": " << x << "\n"
#define doset(x) cout << fixed << setprecision(x)
struct myset{myset(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}};
using ll = long long;
using ld = long double;
using dou = double;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const dou pi = 3.14159265358;
const ll mod1 = 1000000007LL;
const ll mod2 = 998244353LL;
typedef pair<ll,ll> P;
ostream &operator<<(ostream &os, const P q){os << q.first << "," << q.second;return os;}
template<class T, class U> inline bool chmin(T& a, const U& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T, class U> inline bool chmax(T& a, const U& b){ if(a < b){ a = b; return 1; } return 0; }
template<class T, class U> inline bool change(T& a,U& b){if(a > b){swap(a,b);return 1;}return 0;}

//nのm乗をMODで割ったあまりO(logm)
ll modpow(ll n,ll m,ll MOD){
    if(m == 0)return 1;
    if(m < 0)return -1;
    ll res = 1;
    while(m){
        if(m & 1)res = (res * n) % MOD;
        m >>= 1;
        n *= n;
        n %= MOD;
    }
    return res;
}

ll mypow(ll n,ll m){
    if(m == 0)return 1;
    if(m < 0)return -1;
    ll res = 1;
    while(m){
        if(m & 1)res = (res * n);
        m >>= 1;
        n *= n;
    }
    return res;
}

//0の場合のアレンジに注意
template<class T>
T gcd(T a,T b){
    a = abs(a);b = abs(b);
    if(a == 0)return b;
    else if(b == 0)return a;
    if(a < b)swap(a,b);
    if(a % b == 0)return b;
    else return gcd(b,a%b);
}
template<class T>
T lcm(T a,T b){
    return a / gcd(a,b) * b;
}

//素数判定O(sqrt(N))
template<class T>
inline bool isp(T n){
    bool res = true;
    if(n == 1)return false;
    else{
        for(ll i = 2;i * i <= n;i++){
            if(n % i == 0){
                res = false;
                break;
            }
        }
        return res;
    }
}

const ll cmax = 1000000;
vector<ll> fac(cmax),finv(cmax),inv(cmax);

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < cmax; i++){
        fac[i] = fac[i - 1] * i % mod1;
        inv[i] = mod1 - inv[mod1%i] * (mod1 / i) % mod1;
        finv[i] = finv[i - 1] * inv[i] % mod1;
    }
}

// 二項係数計算
ll nCk(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod1) % mod1;
}

template<class T = int>
T in(){T x;cin >> x;return x;}

inline bool Yes(bool b){cout << (b ? "Yes\n":"No\n");return b;}
inline bool YES(bool b){cout << (b ? "YES\n":"NO\n");return b;}

/*----------------------------------マクロここまで----------------------------------*/





int main(){
    myset m;
    ll N;
    cin >> N;
    vector<ll> vec(N);
    rep(i,N)cin >> vec[i];
    ll step = 0,cnt = 0;
    for(;;cnt++){
        bool update = 0;
        rep(i,N){
            if(vec[i] >= N){
                ll kai = vec[i] / N;
                step += kai;
                vec[i] %= N;
                update = 1;
                rep(j,N){
                    if(i != j)vec[j] += kai;
                }
            }
        }
        if(!update)break;
    }
    cout << step << "\n";
}
