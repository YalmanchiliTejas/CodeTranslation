#include <iostream>
using namespace std;

typedef long long ll;

const int MAX_N = 1005;
const int MOD = 1000000007;

int pot(int a, int b) {
    int w = 1;
    while(b > 0) {
        if(b % 2 == 1) {
            w = ll(w) * ll(a) % ll(MOD);
        }
        a = ll(a) * ll(a) % ll(MOD);
        b /= 2;
    }
    return w;
}

int newton[MAX_N][MAX_N], DP[MAX_N][MAX_N];
int sil[MAX_N], odw[MAX_N];

int main() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    
    sil[0] = 1;
    odw[0] = pot(odw[0], MOD - 2);
    for(int i = 1; i <= n; i++) {
        sil[i] = ll(i) * ll(sil[i - 1]) % ll(MOD);
        odw[i] = pot(sil[i], MOD - 2);
    }
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            if(i == 0 || j == 0 || i == j) {
                newton[i][j] = 1;
            } else {
                newton[i][j] = (newton[i - 1][j] + newton[i - 1][j - 1]) % MOD;
            }
        }
    }
    
    for(int i = 0; i <= n; i++) {
        DP[0][i] = 1;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = a; j <= b; j++) {
            DP[i][j] = DP[i][j - 1];
            int akt = 1;
            for(int k = 1; k * j <= i; k++) {
                akt = ll(akt) * ll(newton[i - (k - 1) * j][j]) % ll(MOD);
                if(c <= k && k <= d) {
                    int dod = ll(akt) * ll(odw[k]) % ll(MOD);
                    dod = ll(dod) * ll(DP[i - k * j][j - 1]) % ll(MOD);
                    DP[i][j] = (DP[i][j] + dod) % MOD;
                }
            }
        }
    }
    cout << DP[n][b];
    
    return 0;
}
