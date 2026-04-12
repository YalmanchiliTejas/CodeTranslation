#include <bits/stdc++.h>
/*
#include<algorithm>
#include<array>
#include<cassert>
#include<cmath>
#include<cstdlib>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<typeinfo>
#include<utility>
#include<vector>
*/
#define int long long int
#define double long double
using namespace std;
#define MOD 1000000007
#define INF 1000000000000000007
const int MAX_N = 1 << 17;
#define rep(i, n) for (int(i) = 0, i##_len = (n); (i) < i##_len; (i)++)
#define reps(i, x) for (int(i) = 1; (i) <= (int)(x); (i)++)
#define rrep(i, x) for (int(i) = ((int)(x)-1); (i) >= 0; (i)--)
#define rreps(i, x) for (int(i) = ((int)(x)); (i) > 0; (i)--)
#define FOR(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define pb push_back
#define mp make_pair
#define bit(n) ((int)(1) << (n))
#define all(x) (x).begin(), (x).end()
#define debug(x) std::cout << #x << ": " << (x) << std::endl
#define nint int
using namespace std;

int dy[] = {0, 0, 1, -1, 0};
int dx[] = {1, -1, 0, 0, 0};
typedef pair<int, int> pii;
typedef pair<double, double> dop;
template <class T>
bool chmax(T& a, const T& b)
{
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b)
{
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
struct aaa {
    aaa()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout << fixed << setprecision(20);
    };
} aaaaaaa;

std::vector<int> fac(200001);   //n!(mod M)
std::vector<int> ifac(200001);  //k!^{M-2} (mod M)
//a,bの範囲的にこれだけ配列を用意していけば十分

int mpow(int x, int n)
{  //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    int ans = 1;
    while (n != 0) {
        if (n & 1)
            ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        n = n >> 1;
    }
    return ans;
}

int comb(int a, int b)
{  //aCbをmod計算
    if (a == 0 && b == 0)
        return 1;
    if (a < b || a <= 0)
        return 0;
    int tmp = ifac[a - b] * ifac[b] % MOD;
    return tmp * fac[a] % MOD;
}

signed main()
{
    int n, m, k;
    cin >> n >> m >> k;
    fac[0] = 1;
    ifac[0] = 1;
    for (int i = 0; i < 200000; i++) {
        fac[i + 1] = fac[i] * (i + 1) % MOD;                 // n!(mod M)
        ifac[i + 1] = ifac[i] * mpow(i + 1, MOD - 2) % MOD;  // k!^{M-2} (mod M) ←累乗にmpowを採用
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (((i * (i + 1) / 2) * m % MOD) * m % MOD) * comb(n * m - 2, k - 2);
        sum %= MOD;
    }
    for (int i = 0; i < m; i++) {
        sum += (((i * (i + 1) / 2) * n % MOD) * n % MOD) * comb(n * m - 2, k - 2);
        sum %= MOD;
    }
    cout << sum << endl;
    return 0;
}