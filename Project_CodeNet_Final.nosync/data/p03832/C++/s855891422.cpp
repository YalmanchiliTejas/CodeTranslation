#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define P pair<int, int>
#define LLP pair<long long, long long>
#define REP(i, x, n) for(int i = (x), i##_len = (int)(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = (int)(n) ; i < i##_len ; ++i)
#define repr(i, n) for(int i = (int)(n) - 1 ; i >= 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())

const int IINF = 1e9 + 100;
const long long LLINF = 2e18 + 129;
const long long MOD = 1e9 + 7;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

int b, c, d;
lint memo[1001][1001];
lint perm[1001][1001];
lint fact[1001];
lint inv[1001];

long long power(long long x, long long n){
    long long res = 1;
    x %= MOD;
    while(n > 0LL){
        if(n & 1LL){
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        n >>= 1;
    }
    return res;
}

lint factorial(lint n){
    if(fact[n] >= 0LL){
        return fact[n];
    }
    if(n == 0LL){
        return 1LL;
    }

    return fact[n] = n * factorial(n - 1) % MOD;
}

lint inv_fact(lint n){
    if(inv[n] >= 0LL){
        return inv[n];
    }

    return inv[n] = power(factorial(n), MOD - 2);
}

lint nPr(lint n, lint r){
    if(perm[n][r] >= 0LL){
        return perm[n][r];
    }

    return perm[n][r] = factorial(n) * inv_fact(n - r) % MOD;
}

lint solve(int n, int a){
    if(n == 0){
        return 1LL;
    }
    if(n < 0 || a > b){
        return 0LL;
    }
    if(memo[n][a] >= 0LL){
        return memo[n][a];
    }

    lint res = solve(n, a + 1);

    for(int i = c ; i <= d ; ++i){
        if(i * a > n){
            break;
        }
        res += ((solve(n - i * a, a + 1) * nPr(n, i * a) % MOD) * power(power(factorial(a), i), MOD - 2) % MOD) * inv_fact(i) % MOD;
        res %= MOD;
    }

    return memo[n][a] = res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, a;
    cin >> n >> a >> b >> c >> d;

    fill(memo[0], memo[n + 1], -1LL);
    fill(perm[0], perm[1001], -1LL);
    fill(fact, fact + 1001, -1LL);
    fill(inv, inv + 1001, -1LL);

    lint ans = solve(n, a);
    cout << ans << endl;

    return 0;
}