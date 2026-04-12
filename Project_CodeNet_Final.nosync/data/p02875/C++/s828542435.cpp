#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;
const int MOD = 998244353;

int coef, coef1, coef2, res, i, n;

// rozwiązuje równanie ax=1(%MOD), gdy MOD pierwsze
int inverse(int a, int n = MOD - 2) {
    int r = 1;
    while (n) {
        if (n % 2) r = (r * 1LL * a) % MOD;
        a = (a * 1LL * a) % MOD;
        n >>= 1;
    }
    return r;
}

int main() {
scanf("%d", &n);
res = 1;
for (i=0;i<n;i++) res = (res * 3LL) % MOD;
coef1 = 1;
coef2 = 1;
for (i=n;i>n/2;i--) {
	coef = (coef1 * 1LL * coef2) % MOD;
	res = (res + MOD - coef) % MOD;
	res = (res + MOD - coef) % MOD;
	coef1 = (coef1 * 1LL * i) % MOD;
	coef1 = (coef1 * 1LL * inverse(n - i + 1)) % MOD;
	coef2 = (coef2 * 2LL) % MOD;
}
printf("%d\n", res);
}



