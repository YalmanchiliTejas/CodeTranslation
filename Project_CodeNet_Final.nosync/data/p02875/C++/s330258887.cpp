#include <cstdio>
#include <cstdlib>

using namespace std;

const int mod = 998244353;

class inverse {
    public:
    inverse(int n, int mod);
    ~inverse();
    long long get_inv(int x);
    long long get_fact(int x);
    long long get_invfact(int x);
    long long get_comb(int x, int y);
    
    private:
    int mod;
    long long* inv;
    long long* fact;
    long long* invfact;
};

inverse::inverse(int n, int mod) : mod(mod) {
    inv = (long long *)malloc(sizeof(long long) * (n + 1));
    fact = (long long *)malloc(sizeof(long long) * (n + 1));
    invfact = (long long *)malloc(sizeof(long long) * (n + 1));
    inv[1] = 1;
    for (int i = 2; i <= n; i++) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    fact[0] = invfact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
    for (int i = 1; i <= n; i++) invfact[i] = invfact[i - 1] * inv[i] % mod;
}

inverse::~inverse() {
    free(inv);
    free(fact);
    free(invfact);
}

long long inverse::get_inv(int x) {
    return inv[x];
}

long long inverse::get_fact(int x) {
    return fact[x];
}

long long inverse::get_invfact(int x) {
    return invfact[x];
}

long long inverse::get_comb(int x, int y) {
    return fact[x] * invfact[y] % mod * invfact[x - y] % mod;
}

long long powmod(long long x, long long y) {
    long long ans = 1;
    
    while (y > 0) {
        if (y & 1) ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    
    return ans;
}

int main() {
    int n, i;
    long long ans;
    
    scanf("%d", &n);
    
    inverse inv(n, mod);
    
    ans = powmod(3, n);
    
    for (i = n; i > n / 2; i--) {
        long long x = inv.get_comb(n, i) * powmod(2, n - i) % mod;
        ans -= x * 2;
        while (ans < 0) ans += mod;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
