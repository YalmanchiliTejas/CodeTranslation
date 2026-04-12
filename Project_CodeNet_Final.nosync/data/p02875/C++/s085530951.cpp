#include<iostream>
using namespace std;

typedef long long ll;

// const ll MOD = 1000000007;
const ll MOD = 998244353;
const int MAX_N = 10000005;

ll pot(ll a, ll b) {
    ll w = 1;

    while(b > 0) {
        if(b & 1) {
            w = (w * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }

    return w;
}

ll sil[MAX_N], odw[MAX_N];

ll newton(int n, int k) {
    ll w = (sil[n] * odw[n - k]) % MOD;
    w = (w * odw[k]) % MOD;
    return w;
}

int main() {
    int n;
    cin >> n;

    sil[0] = 1;
    for(int i = 1; i <= n; i++) {
        sil[i] = (sil[i - 1] * ll(i)) % MOD;
    }

//     for(int i = 0; i <= n; i++) cout << sil[i] << " ";
//     cout << endl << " ---------- \n";
    
    odw[n] = pot(sil[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--) {
        odw[i] = (odw[i + 1] * ll(i + 1)) % MOD;
    }
    
//     for(int i = 0; i <= n; i++) cout << odw[i] << " ";
//     cout << endl << " ---------- \n";
    
    ll w = pot(3, n);
    
    for(int k = 1 + n / 2; k <= n; k++) {
        w = (w - 2LL * newton(n, k) * pot(2, n - k) + MOD * MOD) % MOD;
    }
    
    cout << w;
    
    return 0;
}