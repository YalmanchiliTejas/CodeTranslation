//https://arc096.contest.atcoder.jp/tasks/arc096_c

#include<bits/stdc++.h>
#define int long long
const int N = 3005;
using namespace std;

int n, mod, f[N][N], c[N][N], ans;

void add(int&a, int b){
    a += b; if (a >= mod) a -= mod;
}

int po(int n, int k, int Mod = mod){
    int ans = 1;
    while(k){
        if (k&1) ans = 1LL * ans * n % Mod;
        n = 1LL * n * n % Mod;
        k >>= 1;
    }
    return ans;
}

int cal(int x, int Max){
    x = po(po(2, x), mod-2);
    x = mod-x+1; if (x >= mod) x -= mod;
    return po(x, Max);
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> mod;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++){
            f[i][j] = ((j == 0) ? 1 : (1LL * f[i-1][j] * (j+1) + f[i-1][j-1]) % mod);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++){
            c[i][j] = ((j == 0) ? 1 : (c[i-1][j] + c[i-1][j-1]) % mod);
        }
    }
    for (int a = 0; a <= n; a++){
        int sum = 0;
        for (int i = 0; i <= a; i++) {
            add(sum, 1LL * f[a][i] * po(po(2, n-a), i) % mod);
        }
        sum = 1LL * sum * c[n][a] % mod;
        sum = 1LL * sum * po(2, po(2, n-a, mod-1)) % mod;
        if (a&1) {
            sum = -sum; if (sum < 0) sum += mod;
        }
        add(ans, sum);
    }
    cout << ans;
}
