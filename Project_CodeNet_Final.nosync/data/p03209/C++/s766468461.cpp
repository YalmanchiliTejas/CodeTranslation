#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define show(x) cerr << #x << x << endl

typedef long long ll;
typedef unsigned long long ull;

constexpr const int INT_INF=0x3f3f3f3f; // 1061109567
constexpr const ll LL_INF=0x3f3f3f3f3f3f3f3f; // 4557430888798830399

template <typename T> bool chmin(T &a, T b) {
    if (a > b) {a = b;return true;}return false;
}

template <typename T> bool chmax(T &a, T b) {
    if (a < b) {a = b;return true;}return false;
}

// INT
#define GCD(a, b) __gcd(a, b)
template <typename T> T LCM(T a, T b) {return a / GCD(a, b) * b;}
template <typename T> T EXTGCD(T a, T b, T& x, T& y) {
    T d = a;
    if (b != 0) {d=EXTGCD(b,a%b,y,x);y-=(a/b)*x;}
    else x=1,y=0;
    return d;
}
template <typename T> bool is_prime(T a) {
    for(int i=2;i*i<=a;i++)if(a%i==0)return 1;
    return 0;
}

// MOD
const ll MOD = 1000000000 + 7;
#define add(a, b) ((a % MOD) + (b % MOD)) % MOD
#define mul(a, b) ((a % MOD) * (b % MOD)) % MOD
#define sub(a, b) ((a % MOD) + MOD - (b % MOD)) % MOD
template <typename T> T mod_inverse(T a, T mod, bool prime){ // if mod is prime, "prime" is true.
    if(prime){
        T tmp=mod-2,now=a,res=1;while(tmp){if(tmp&1)res=mul(res,now);now=mul(now,now);tmp>>=1;}
        return res;
    }else{T x,y;EXTGCD(a,mod,x,y);return (mod+x%mod)%mod;}
}
#define divide(a, b) ((a % MOD) * (mod_inverse(b, MOD, true))) % MOD

//
//
//  　　┓　　　┏
//  　＊┗┓　┏┛
//  　　　┫　┣　＊
//  　┏┳┻━┻┳┓
//  　┗┫　　　┣┛
//  ＊　┣　　━┃　＊        Merry Christmas!!
//  　┏┛　　〃┃
//  　┃●　　　┣━┳┓
//  　┗┻┳━━┛　┣┛
//  　＊　┃┏┓┣┓┃
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW

int n;
ll k;
ll p[51], sz[51];

ll dfs(int L, ll x) {
    if (L == 0) {
        if (x <= 0) return 0L;
        else if (x == 1) return 1L;
        else assert(0);
    }
    if (x == 1) return 0L;
    if (x > 1 && x <= sz[L - 1] + 1) return dfs(L - 1, x - 1);
    if (x > sz[L - 1] + 1 && x <= sz[L - 1] + 2) return p[L - 1] + 1;
    if (x > sz[L - 1] + 2 && x <= sz[L - 1] * 2 + 2) return p[L - 1] + 1 + dfs(L - 1, x - sz[L - 1] - 2);
    if (x > sz[L - 1] * 2 + 2 && x <= sz[L - 1] * 2 + 3) return p[L];
    return 0L;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    FILE *stream1;
    //FILE *stream2;
    stream1 = freopen("C:\\Users\\naruse\\CLionProjects\\competitive\\cmake-build-debug\\in.txt", "r", stdin);
    //stream2 = freopen("out.txt", "w", stdout);
    if (stream1 == nullptr) return 0;
    //if (stream2 == NULL) return 0;
#endif
    cin >> n >> k;
    p[0] = 1;
    sz[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] =p[i - 1] * 2 + 1;
        sz[i] = sz[i - 1] * 2 + 3;
    }
    cout << dfs(n, k) << endl;
#ifdef  LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
#endif
    return 0;
}