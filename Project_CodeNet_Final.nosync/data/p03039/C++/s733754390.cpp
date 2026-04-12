#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

#define rep(i, x, y) for (i64 i = i64(x), i##_max_for_repmacro = i64(y); i < i##_max_for_repmacro; ++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

const int inf = 1.01e9;
const i64 inf64 = 4.01e18;
const double eps = 1e-9;

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "[";
    for (const auto &v : vec) {
        os << v << ",";
    }
    os << "]";
    return os;
}

template <typename T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<typename T, size_t size> void fill(T (&ary)[size], const T& val){
    fill_n((T*)ary, size, val);
}

i64 extgcd(i64 a, i64 b, i64 &x, i64 &y) {
    i64 d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

i64 mod_inverse(i64 a, i64 m) {
    i64 x, y;
    if (extgcd(a, m, x, y) == 1) return (x + m) % m;
    return 0;
}

vector<i64> fact;
void init_fact(i64 n, i64 m) {
    fact.resize(n + 1);
    fact[0] = fact[1] = 1;
    for (i64 i = 2; i <= n; ++i) fact[i] = (i * fact[i - 1]) % m;
}

i64 mod_comb(i64 n, i64 k, i64 p) {
    if (n < 0 or k < 0 or n < k) return 0;

    if(n>=p) return 0;

    if(n-k<k) return mod_comb(n,n-k,p);

    i64 num = 1, den = 1;
    for (i64 i = 0; i < k; ++i) {
        num = num * ((n - i) % p) % p;
        den = den * (i + 1) % p;
    }
    return num * mod_inverse(den, p) % p;
}

void solve() {
    const i64 mod = 1'000'000'007;

    i64 N,M,K;
    cin >> N >> M >> K;

    i64 ans=0,tmp=mod_comb(N*M-2,K-2,mod);
    {
        i64 sum=0;
        rep(d,1,M){
            i64 cnt=M-d;
            sum+=d*cnt%mod*N%mod*N%mod*tmp%mod;
        }
        ans+=sum;
        ans%=mod;
    }
    {
        i64 sum=0;
        rep(d,1,N){
            i64 cnt=N-d;
            sum+=d*cnt%mod*M%mod*M%mod*tmp%mod;
        }
        ans+=sum;
        ans%=mod;
    }

    cout << ans << endl;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
