#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <numeric>
#include <string.h>
using namespace std;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const long long INFL = 1e18;
const int MOD = 1000000007;
const int MAX = 210000;
const int MAX_LOOP = 100000;
int a, b, c, x, y;

int gcd(int a, int b) {
    return b != 0 ? gcd(b, a % b) : a;
}

void solve() {
    int ans = INF;
    cin >> a >> b >> c >> x >> y;
    cout << min({ a * x + b * y, c * 2 * x + b * max(0, y - x), a * max(0, x - y) + c * 2 * y}) << endl;
    return;
}
//逆元を求める関数
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
      fac[i] = fac[i-1] * i % MOD;
      inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
      finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
//組み合わせ
long long COM (int n, int k) {
    if(n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}
int main(int args, char* argv[]) {
    solve();
}

