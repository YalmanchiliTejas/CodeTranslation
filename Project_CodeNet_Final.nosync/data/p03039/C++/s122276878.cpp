#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;

vector<long long int> inverse;
vector<long long int> f, f_inverse;

void factorial_Initialize(int max){
    vector<long long int> a(max+1,1);
    inverse = a;
    f = a;
    f_inverse = a;

    for (int i=2; i<=max; i++){
        inverse[i]   = MOD - inverse[MOD % i] * (MOD / i) % MOD;
        f[i]         = f[i-1]         * i          % MOD;
        f_inverse[i] = f_inverse[i-1] * inverse[i] % MOD;
    }
}

long long int nCr(int n, int r){
    if(n < r || r < 0) return 0;
    if (n >= f.size()){
        factorial_Initialize(n);
    }
    return f[n] * f_inverse[r] % MOD * f_inverse[n-r] % MOD;
}

long long int modpow(int b, int p){
    long long int num = 1, power = b;
    for(int i=0; i<=30; i++){
        if((p>>i) & 1) num *= power;

        num %= MOD;
        power *= power;
        power %= MOD;
    }
    return num;
}

int main(){
    long long int n, m, k;
    cin >> n >> m >> k;

    long long int x = 0, y = 0;
    for(long long int i=1; i<n; i++){
        long long int add = i * (n-i) * m * m;
        add %= MOD;
        add *= nCr(n*m-2, k-2);
        add %= MOD;

        x += add;
        x %= MOD;
    }
    for(long long int i=1; i<m; i++){
        long long int add = i * (m-i) * n * n;
        add %= MOD;
        add *= nCr(n*m-2, k-2);
        add %= MOD;
        
        y += add;
        y %= MOD;
    }

    long long int ans = x + y;
    ans %= MOD;
    cout << ans << endl;
    return 0;
}