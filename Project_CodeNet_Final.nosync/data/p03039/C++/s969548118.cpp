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

long long f(int a){
    return (long long) a*(a+1)/2 % mod;
}
long long g(int a, int b){
    if(a <= 0 || b <= 0)return 0;
    long long res = a*f(b) + b*f(a);
    return res%mod;
}
int main(void){
    int n, m, k, nm;
    long long ans = 0;
    cin >> n >> m >> k;
    nm = n*m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            long long t = f(i) + f(j) + f(n-1-i) + f(m-1-j);
            t += g(i, j);
            t += g(i, m-1-j);
            t += g(n-1-i, j);
            t += g(n-1-i, m-1-j);
            t %= mod;
            ans += t * mod_comb(nm-2, k-2);
            ans %= mod;
            
        }
    }
    cout << ans * mod_div(2) % mod<< endl;
}
