#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <numeric>
#include <functional>
#include <math.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define INF ((int)1e9)
#define INFLL ((ll)1e18)
#define MOD (1000000007LL)

class mod {
public:
    mod() {m_n = 0;}
    mod(ll n) {if (n >= 0) m_n = n % MOD; else m_n = n % MOD + MOD;}
    friend bool operator== (const mod& a, const mod& b) {return a.m_n == b.m_n;}
    friend bool operator!= (const mod& a, const mod& b) {return !(a == b);}
    friend mod operator+ (const mod& a, const mod& b) {return (a.m_n + b.m_n) % MOD;}
    friend mod& operator+= (mod& a, const mod& b) {return a = a + b;}
    friend mod operator- (const mod& a) {return -a.m_n;}
    friend mod operator- (const mod& a, const mod& b) {return (a.m_n + (-b.m_n)) % MOD;}
    friend mod& operator-= (mod& a, const mod& b) {return a = a - b;}
    friend mod operator* (const mod& a, const mod& b) {return (a.m_n * b.m_n) % MOD;}
    friend mod& operator*= (mod& a, const mod& b) {return a = a * b;}
    friend mod mod_pow(const mod& n, ll r) {
        if (r == 0) {
            return 1;
        } else if (r < 0) {
            return mod_pow(n, (MOD - 2) * (-r));
        } else if (r % 2 == 0) {
            mod tmp = mod_pow(n, r / 2);
            return tmp * tmp;
        } else {
            return n * mod_pow(n, r - 1);
        }
    }
    friend mod operator/ (const mod& a, const mod& b) {return a * mod_pow(b, -1);}
    friend mod& operator/= (mod& a, const mod& b) {return a = a / b;}
    friend ostream& operator<< (ostream& os, const mod& n) {os << n.m_n; return os;}
    friend istream& operator>> (istream& is, mod& n) {ll tmp; is >> tmp; n = mod(tmp); return is;}
private:
    ll m_n;
};
mod mod_pow(ll n, ll r) {return mod_pow(mod(n), r);}

#define FACT_MAX 1000000
mod t_fact[FACT_MAX], t_fact_inv[FACT_MAX];
mod fact(int n)
{
    if (n == 0 || n == 1) return t_fact[n] = 1;
    if (t_fact[n] != 0) return t_fact[n];
    else return t_fact[n] = n * fact(n-1);
}
mod fact_inv(int n)
{
    if (t_fact_inv[n] != 0) return t_fact_inv[n];
    else return t_fact_inv[n] = mod_pow(fact(n), -1);
}
mod comb(int n, int k) {if (n < 0 || k < 0 || k > n) return 0; else return fact(n) * fact_inv(n - k) * fact_inv(k);}
mod multi_choose(int n, int k) {return comb(n + k - 1, k);}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    for (int n = 0; n <= N; ++n) {
        fact(n); fact_inv(n);
    }
    
    vector<mod> DP(N+1);
    DP[0] = 1;
    for (int F = C; F*A <= N && F <= D; ++F) {
        DP[F*A] = mod_pow(t_fact_inv[A], F) * t_fact_inv[F];
    }
    for (int d = 1; d <= B-A; ++d) {
        for (int n = N; n >= 0; --n) {
            for (int  F = C; F*(A+d) <= n && F <= D; ++F) {
                DP[n] += DP[n-F*(A+d)] * mod_pow(t_fact_inv[A+d], F) * t_fact_inv[F];
            }
        }
    }
    cout << DP[N] * fact(N) << endl;

    return 0;
}
