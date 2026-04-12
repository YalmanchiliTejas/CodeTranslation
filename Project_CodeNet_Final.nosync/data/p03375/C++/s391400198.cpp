#include <bits/stdc++.h>
#define ll long long
#define OO 1e9
using namespace std;
ll ways[3001];
ll ways2[3001][3001];
ll fact[3001];
ll inv[3001];

ll mem[10000001][2];
int n, m;
ll pow1(ll n, ll p, ll MOD){
    if(MOD != m && MOD != m-1)assert(0);
    if(n == 2 && p < 10000001 && mem[p][MOD == m ? 1 : 0] != -1)
        return mem[p][MOD == m ? 1 : 0];
    ll cur, res;
    cur = n;
    res = 1;
    ll z = p;
    while(p){
        if(p & 1){
            res *= cur;
            res %= MOD;
        }

        p /= 2;
        cur *= cur;
        cur %= MOD;
    }
    if(n == 2 && z < 10000001)
        mem[z][MOD == m ? 1 : 0] = res;
    return res;
}
ll C(int n, int k){
    return fact[n] * inv[k] % m * inv[n-k] % m;
}
//int p1[3001];
//int p2[3001];
int main(){
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin >> n >> m;
    for(int i = 0;i <= n;i++){
        ways2[i][0] = 1;
    }
    memset(mem, -1, sizeof(mem));

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= i;j++){
            ways2[i][j] = ((j+1) * ways2[i-1][j] % m + ways2[i-1][j-1]) % m;
            ways2[i][j] %= m;
        }
    }


    for(int i = 0;i <= n;i++)
        for(int j = 0;j <= i;j++)
            (ways[i] += ways2[i][j] * pow1(2, (n-i) * j, m) % m * pow1(2, pow1(2, n-i, m-1), m) % m) %= m;
    fact[0] = inv[0] = 1;
    for(int i = 1;i < 3001;i++)
        fact[i] = fact[i-1] * i % m, inv[i] = pow1(fact[i], m - 2, m);

    ll res = 0;
    for(int i = 0;i <= n;i++){
        res += ((i&1) ? -1 : 1) * C(n, i) * ways[i] % m;
        res %= m;
    }
    if(res < 0)res += m;
    cout << res;
    return 0;
}

