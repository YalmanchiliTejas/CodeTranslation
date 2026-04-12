#include <iostream>
#include <vector>
using namespace std;
long long const mod = 998244353;
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

int main(void){
    long long n, al, ng = 0;
    cin >> n;
    al = mod_pow(3, n);
    for(int i=0;i<n/2;i++){
        ng += mod_comb(n, i) * mod_pow(2, i);
        ng %= mod;
    }
    cout << (al - ng*2 + mod*2) % mod << endl;
}
