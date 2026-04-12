#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
class BinomialCoefficient {
int pow(int x, int p) {
    int ans = 1;
    while(p) {
        if(p % 2) ans = ((long long)ans * x) % prime;
        x = ((long long)x * x) % prime;
        p /= 2;
    }
    return ans;
}
public:
    int prime;
    vector <int> f, inv_f;
    BinomialCoefficient(int maxN, int prime = 1e9 + 7) {
        this->prime = prime;
        f.assign(maxN + 1, 1);
        inv_f.assign(maxN + 1, 1);
        inv_f[0] = pow(1, prime - 2);
        for(int i = 1; i <= maxN; i++) {
            f[i] = (long long)f[i - 1] * i % prime;
            inv_f[i] = pow(f[i], prime - 2);
        }
    }
    int choose(int N, int K) {
        return (((long long)f[N] * inv_f[N - K] % prime) * inv_f[K]) % prime;
    }
};
 
const int MOD = 1e9 + 7;struct ModularInt{int n;ModularInt(int n_=0):n(n_){}};
ModularInt operator-(ModularInt a){return -a.n+MOD*(a.n!=0);}
ModularInt operator+(ModularInt a,ModularInt b){int x=a.n+b.n;return x-(x>=MOD)*MOD;}
ModularInt operator-(ModularInt a,ModularInt b){int x=a.n-b.n;return x+(x<0)*MOD;}
ModularInt operator*(ModularInt a,ModularInt b){return (long long)a.n*b.n%MOD;}
ModularInt &operator+=(ModularInt &a,ModularInt b){return a=a+b;}
ModularInt &operator-=(ModularInt &a,ModularInt b){return a=a-b;}
ModularInt &operator*=(ModularInt &a,ModularInt b){return a=a*b;}
istream &operator>>(istream &i,ModularInt &a){return i>>a.n;}
ostream &operator<<(ostream &o,ModularInt a){return o<<a.n;}
int N, M, K;
 
BinomialCoefficient binomialCoefficient(200005, MOD);
 
ModularInt solve(int n, int m, int k) {
    ModularInt bc = binomialCoefficient.choose(n * m - 2, k - 2);
    ModularInt ans = 0;
    for(int d = 1; d < m; d++) {
        ans += (ModularInt)d * n * n * (m - d) * bc;
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
    cout << solve(N, M, K) + solve(M, N, K) << endl;
}
