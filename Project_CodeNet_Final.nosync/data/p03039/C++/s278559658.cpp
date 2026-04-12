#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}

ll modpow(ll a, ll p) {
    if(p == 0)
        return 1;
    if(p % 2 == 0) {
        ll halfp = p / 2;
        ll half = modpow(a, halfp);
        return half * half % MOD;
    } else {
        return a * modpow(a, p - 1) % MOD;
    }
}

ll calcComb(ll a, ll b) {
    if(b > a - b) {
        return calcComb(a, a - b);
    }
    ll ansMul = 1;
    ll ansDiv = 1;
    REP(i, b) {
        ansMul *= (a - i);
        ansDiv *= (i + 1);
        ansMul %= MOD;
        ansDiv %= MOD;
    }
    ll ans = ansMul * modpow(ansDiv, MOD - 2);
    ans %= MOD;
    return ans;
}

int N, M, K;
long long ans = 0;
vector<pair<int, int>> v;
int main() {
    cin >> N >> M >> K;
    ll ans = 0;
    ll p = calcComb(N * M - 2, K - 2);
    REP(i, N) {
        ans += i * (N - i) * M * M;
        ans %= MOD;
    }
    REP(i, M) {
        ans += i * (M - i) * N * N;
        ans %= MOD;
    }
    ans *= p;
    ans %= MOD;
    cout << ans << endl;
}