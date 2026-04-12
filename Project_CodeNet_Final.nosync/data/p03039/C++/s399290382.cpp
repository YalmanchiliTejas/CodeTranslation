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
const ll INF = (1ll<<60);
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


int dx[5] = {1, 0, -1, 0};
int dy[5] = {0, 1, 0, -1};

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

class Combination{
    long long powmod(long long a, long long p){
        long long ans = 1LL;
        long long mul = a;
        while(p>0){
            if((p&1)==1) {
                ans = (ans * mul) % MOD;
            }
            mul=(mul*mul)%MOD;
            p>>=1;
        }
        return ans;
    }

public:
    int N;
    long long mod;
    vector<long long> fact;
    vector<long long> revfact;

    Combination(long long n, long long m) : N(n), mod(m), fact(n+1), revfact(n+1){
        fact[0]=1;
        for(int i=1; i<=N; i++){
            fact[i]=fact[i-1]*i;
            fact[i]%=mod;
        }

        revfact[N] = powmod(fact[N], mod-2);
        for(int i=N-1; i>=0; i--){
            revfact[i]=revfact[i+1]*(i+1)%mod;
        }
    }

    long long getCombination(long long a, long long b){
        if(a<0 || b<0) return 0;
        if(b>a)return 0;
        return fact[a]*revfact[b]%mod*revfact[a-b]%mod;
    }
};


const int mod = 1000000007;
struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};

int main() {
    ll N, M, K; cin >> N  >> M >> K;
    Combination com = Combination(N*M+1, MOD);
    mint ans = mint(0);

    for(int i=1; i<N; i++){
        ans+=i*(N-i)*M*M*com.getCombination(N*M-2, K-2);
    }

    for(int i=1; i<M; i++){
        ans+=i*(M-i)*N*N*com.getCombination(N*M-2, K-2);
    }

    cout << ans.x << endl;
    return 0;
}
