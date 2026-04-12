#include <cstdio>
#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
#include <numeric>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <stack>

using namespace std;

#define INFint (1<<30)
#define BOUND 27182818284
#define MAT 2

typedef long long ll;
typedef long long int lli;
typedef pair<ll, ll> P;

ll MOD = 1000000007;
const ll INF = (1ll << 60);
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for(int i=int(a);i<int(b);++i)

template<class T>
bool umax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool umin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

// gcd
template<typename T>
T gcd(T a, T b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int findGCD(vector<int> arr) {
    int result = arr[0];
    for (auto a: arr) {
        result = gcd(a, result);
    }
    return result;
}

template<typename T>
T lcm(T m, T n) {
    // 引数に0がある場合は0を返す
    if ((0 == m) || (0 == n))
        return 0;
    return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
    fill((T *) array, (T *) (array + N), val);
}


// v.front() = -BOUND;
// v.back() = BOUND;

//struct edge{
//    int cost, to;
//
//    edge(int in_cost, int in_to){
//        cost=in_cost;
//        to=in_to;
//    }
//    bool operator<(const edge &a) const
//    {
//        return cost > a.cost;
//    }
//};
ll euler_phi(ll n) {
    ll ret = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ret -= ret / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ret -= ret / n;
    return ret;
}

class Combination {
    long long powmod(long long a, long long p) {
        long long ans = 1LL;
        long long mul = a;
        while (p > 0) {
            if ((p & 1) == 1) {
                ans = (ans * mul) % MOD;
            }
            mul = (mul * mul) % MOD;
            p >>= 1;
        }
        return ans;
    }

public:
    int N;
    long long mod;
    vector<long long> fact;
    vector<long long> revfact;

    Combination(int n, long long m) : N(n), mod(m), fact(n + 1), revfact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= N; i++) {
            fact[i] = fact[i - 1] * i;
            fact[i] %= mod;
        }

        revfact[N] = powmod(fact[N], mod - 2);
        for (int i = N - 1; i >= 0; i--) {
            revfact[i] = revfact[i + 1] * (i + 1) % mod;
        }
    }

    long long getCombination(int a, int b) {
        if (a < 0 || b < 0) return 0;
        if (b > a)return 0;
        return fact[a] * revfact[b] % mod * revfact[a - b] % mod;
    }
};




int main() {
    int N,M; cin >> N >> M;
    if(N == M){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
