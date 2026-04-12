#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <cctype>
#include <fstream>
#include <cstring>
#include <unordered_map>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 2000000000
#define LINF 9000000000000000000
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define du(x) cout<<#x<<'='<<x<<endl
#define du2(x,y) cout<<#x<<'='<<x<<' '<<#y<<'='<<y<<'\n'<<endl
#define du3(x,y,z) cout<<#x<<'='<<x<<' '<<#y<<'='<<y<<' '<<#z<<'='<<z<<'\n'<<endl
#define darr(arr,n) rep(i,(n-arr)){cout<<*(arr+i)<<' ';}cout<<endl
#define ddarr(arr,a,b) rep(i,a){rep(j,b){cout<<*(arr+i*b+j)<<' ';}cout<<endl;}
#define ddd ifstream in("Text.txt");cin.rdbuf(in.rdbuf());


ll mod_pow(ll n, ll p) {
    if (p == 0) return 1;
    ll res = mod_pow(n*n%MOD, p / 2);
    if (p % 2 == 1) res = res * n % MOD;
    return res;
}

ll Combination(int n, int r) {//階乗は英語でFactorial
    vector<ll> fct(n + 1, 1); // fact[n] = n! の mod
    for (int i = 1; i <= n; i++) {
        fct[i] = i * fct[i - 1] % MOD;
    }

    vector<ll> invfct(n + 1, 1); // invfact[n] = 1/n! の mod
    invfct[n] = mod_pow(fct[n], MOD - 2) % MOD;// 1/n!を繰り返し二乗法で求める
    for (int i = n - 1; i >= 1; i--) {
        invfct[i] = (i + 1)*invfct[i + 1] % MOD;
    }
    // Combination(n,r)を計算
    ll Co = (fct[n] * invfct[r] % MOD)*invfct[n - r] % MOD;
    return Co;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    ll ans = 0;
    for (int dx = 1; dx < M; dx++) {
        ll A = (N*N*(M - dx)) % MOD;
        ans = (ans + A * dx % MOD) % MOD;
    }
    for (int dy = 1; dy < N; dy++) {
        ll A = (M*M*(N - dy)) % MOD;
        ans = (ans + A * dy % MOD) % MOD;
    }

    cout << ans * (Combination(N*M - 2, K - 2) % MOD) % MOD << endl;
}