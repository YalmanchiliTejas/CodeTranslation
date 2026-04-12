#include <iostream>
#include <vector>
using namespace std;
long long const mod = 1000000007;
long long mod_fact(int x){
    static vector<long long> fact = {1, 1};
    if(x < 0)return 0; //
    if(x < fact.size())return fact[x];
    for(int i = fact.size(); i <= x; i++){
        fact.push_back((fact[i-1] * i) % mod);
    }
    return fact[x];
}

long long mod_pow(long long a, long long b){
    long long res = 1;
    a %= mod;
    while(b > 0){
        if(b%2 == 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

long long mod_div(long long a){
    return mod_pow(a, mod-2);
}

long long mod_comb(int a, int b){
    if(b < 0 || a < b)return 0;
    if(b > a/2)return mod_comb(a, a-b);
    return (((mod_fact(a) * mod_div(mod_fact(a-b))) % mod) * mod_div(mod_fact(b))) % mod;
}

long long func(int a, int b){
    return mod_fact(a*b) * mod_pow(mod_div(mod_fact(a)), b) % mod * mod_div(mod_fact(b)) % mod;
}

vector< vector<long long> > dp;

int main(void){
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    dp.assign(2, vector<long long>());
    for(int i=0;i<2;i++){
        dp[i].assign(n+1, 0);
    }

    for(int k=c;k<=d&&k*a <= n;k++){
        dp[a%2][k*a] = mod_comb(n, k*a) * func(a, k) % mod;
    }
    dp[0][0] = dp[1][0] = 1;
    for(int i=a+1;i<=b;i++){
        int ia = i%2, ib = (i+1)%2;
        for(int j=1;j<=n;j++){
            dp[ia][j] = dp[ib][j];

            for(int k=c;k<=d && j - i*k >= 0;k++){
                dp[ia][j] += dp[ib][j - i*k] * mod_comb(n-j+i*k, i*k) % mod * func(i, k) % mod;
                dp[ia][j] %= mod;
            }
        }
    }
    cout << dp[b%2][n] << endl;
}
