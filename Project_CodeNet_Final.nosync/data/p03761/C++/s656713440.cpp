#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <cassert>
#include <functional>
#include <set>
#include <deque>
#include <list>
using namespace std;
typedef long long ll;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
const int INF = 1<<29;
#define LNF __LONG_LONG_MAX__
const ll MOD = 1000000007;
const int MAX = 200000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// 法mでのaの逆元を計算
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
//最大公約数
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }
//最小公倍数
int lcm(int x, int y) { return x / gcd(x, y) * y; }
// nが大きく,kが10^7程度の時の二項係数
long long com[200005];
void combination(long long n,long long k){
    com[0] = 1;
    for(int i=1;i<=k;i++){
        com[i] = (com[i-1]*(n-i+1)%MOD)*modinv(i,MOD)%MOD;
    }
}

int main(){
    int n; cin >> n;
    string S;
    vector<int> mm(26,INF);
    string out="";
    for(int i=0;i<n;i++){
        vector<int> c(26,0);
        cin >> S;
        for(int j=0;j<S.size();j++){
            c[S[j]-'a']++;
        }
        for(int j=0;j<26;j++){
            if(mm[j]>c[j]) mm[j] = c[j];
        }
    }
    
    for(int i=0;i<26;i++){
        int t = mm[i];
        if(t==0) continue;
        for(int j=0;j<t;j++){
            cout << (char)('a'+i);
        }
    }
    printf("\n");

    return 0;
}
