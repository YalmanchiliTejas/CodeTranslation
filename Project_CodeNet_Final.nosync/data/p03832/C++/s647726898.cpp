#include <bits/stdc++.h>

#define mp make_pair
#define X first
#define Y second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int N = 1e3 + 10;
const int MOD = 1e9 + 7;

ll powMod(ll n, ll k){
    if (k == 0)
        return 1;
    ll res = powMod(n, k >> 1);
    res = res * res % MOD;
    if (k & 1)
        res = res * n % MOD;
    return res;
}

int n, a, b, c, d;
ll C[N][N], rev[N], F[N][N];

void init(){
    rev[0] = 1;
    FOR(i, 1, n)
        rev[i] = powMod(i, MOD - 2);
    C[0][0] = 1;
    FOR(i, 1, n){
        C[i][0] = 1;
        FOR(j, 1, i)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> a >> b >> c >> d;
    init();
    F[0][0] = 1;
    FOR(i, 1, n)
        FOR(j, 0, n){
            F[i][j] = F[i - 1][j];
            if (a <= i && i <= b){
                ll cur = 1;
                for(int k = i; k <= j; k += i){
                    cur = cur * C[j - k + i][i] % MOD * rev[k / i] % MOD;
                    if (c <= k / i && k / i <= d)
                        F[i][j] = (F[i][j] + F[i - 1][j - k] * cur) % MOD;
                }
            }
        }

    cout << F[n][n];
    return 0;
}