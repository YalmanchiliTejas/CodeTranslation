#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define debug(x) cerr << #x << " = " << (x) << endl;
template<typename T>
ostream& operator<<(ostream& o, vector<T>& v) {
    for (auto& x : v) o << x << ' ';
    return o;
}

const int MOD = (int)1e9 + 7;
void add(int &a, int b){
    a += b;
    if (a >= MOD) a -= MOD;
}
int exp(int a, int b){
    if (b == 0) return 1;
    if (b & 1) {
        return (ll)a * exp(a, b-1) % MOD;
    }
    int tmp = exp(a, b/2);
    return (ll)tmp * tmp % MOD;
}

const int MAXN = 1024;
int binom[MAXN][MAXN];
int fact[MAXN], ifact[MAXN];
int N, A, B, C, D;
ll memo[MAXN][MAXN];
ll dp(int n, int k){
    ll &res = memo[n][k];
    if (res != -1) return res;
    if (k > B) return res = (n == 0);
    res = dp(n, k + 1);
    ll den = 1;
    for (int i = C; i <= D; i++){
        int tk = i * k;
        if (tk > n) break;
        if (i == C){
            for (int iter = 0; iter < C-1; iter++)
                den = den * ifact[k] % MOD;
        }
        den = den * ifact[k] % MOD;
        ll cur = (ll)binom[n][tk] * fact[tk] % MOD * den % MOD;
        cur = cur * dp(n - tk, k + 1) % MOD * ifact[i] % MOD;
        res += cur;
    }
    res %= MOD;
    //cout << n << ' ' << k << " = " << res << endl;
    return res;
}

int main(){
    std::ios_base::sync_with_stdio(false); cin.tie(0);
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < MAXN; i++){
        fact[i] = (ll)fact[i-1] * i % MOD;
        ifact[i] = exp(fact[i], MOD - 2);
    }

    for (int i = 0; i < MAXN; i++)
        binom[i][0] = binom[i][i] = 1;
    for (int i = 2; i < MAXN; i++){
        for (int j = 1; j < i; j++){
            binom[i][j] = (binom[i-1][j] + binom[i-1][j-1]) % MOD;
        }
    }
    cin >> N >> A >> B >> C >> D;
    memset(memo, -1, sizeof memo);
    int res = dp(N, A);
    cout << res << endl;
}
