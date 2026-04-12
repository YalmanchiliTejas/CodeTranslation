#include <bits/stdtr1c++.h>

#define MAX 1010
#define MOD 1000000007
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))

using namespace std;

int n, a, b, c, d, inv[MAX], fact[MAX], dp[MAX][MAX], binomial[MAX][MAX];

int expo(int a, int b){
    int res = 1;

    while (b){
        if (b & 1) res = (long long)res * a % MOD;
        a = (long long)a * a % MOD;
        b >>= 1;
    }
    return res;
}

int group(int n, int s, int c){
    int i;
    long long res = 1;

    for (i = 1; i <= c; i++){
        res = (res * binomial[n][s]) % MOD;
        n -= s;
    }
    return res * inv[c] % MOD;
}

int F(int i, int p){
    if (i > b) return (p == 0);
    if (dp[i][p] != -1) return dp[i][p];

    long long x, res = F(i + 1, p);
    for (int j = c; j <= d && (j * i) <= p; j++){
        x = (long long)F(i + 1, p - i * j) * group(p, i, j);
        res = (res + x) % MOD;
    }

    return (dp[i][p] = (res % MOD));
}

void generate(){
    int i, j;

    for (i = 0; i < MAX; i++){
        for (j = 0; j <= i; j++){
            if (i == j || j == 0) binomial[i][j] = 1;
            else binomial[i][j] = (binomial[i - 1][j] + binomial[i - 1][j - 1]) % MOD;
        }
    }
    for (fact[0] = 1, i = 1; i < MAX; i++) fact[i] = (long long)fact[i - 1] * i % MOD;
    for (i = 0; i < MAX; i++) inv[i] = expo(fact[i], MOD - 2);
}

int main(){
    generate();
    int i, j, k, l, res;

    while (scanf("%d %d %d %d %d", &n, &a, &b, &c, &d) != EOF){
        memset(dp, -1, sizeof(dp));
        printf("%d\n", F(a, n));
    }
    return 0;
}
