#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

const int mod = 1000000007;
int add(int a, int b) { return (a += b) < mod? a : a - mod; }
int sub(int a, int b) { return (a -= b) >=  0? a : a + mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
void adds(int& a, int b) { a = add(a, b); }
void subs(int& a, int b) { a = sub(a, b); }
void muls(int& a, int b) { a = mul(a, b); }
void maxs(int& a, int b) { a = max(a, b); }
void mins(int& a, int b) { a = min(a, b); }
int pwr(int a, ll p) {
    if (p == 0) return 1;
    if (p & 1) return mul(a, pwr(a, p - 1));
    return pwr(mul(a, a), p / 2);
}
int inv(int a) { return pwr(a, mod - 2); }

int dp[10000][101];
int a[10000];
string k;
int d;
int n;

int f(int x, int s)
{
    if (x == n)
        return (s == 0 ? 1 : 0);

    int& sol = dp[x][s];
    if (sol != -1)
        return sol;

    sol = 0;
    for (int i = 0; i <= 9; ++i)
        adds(sol, f(x + 1, (s + i) % d));
    return sol;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> d;
    n = k.size();
    for (int i = 0; i < n; ++i)
        a[i] = k[i] - '0';

    memset(dp, -1, sizeof dp);
    int sol = f(1, 0);
    int dsum  = 0;
    for (int j = 0; j < n; ++j)
    {
        int l = (j == 0 ? a[j] - 1 : a[j]);
        for (int i = (j != n - 1 ? 1 : 0); i <= l; ++i)
            adds(sol, f(j + 1, (dsum + a[j] - i) % d));
        dsum += a[j];
    }
    cout << sub(sol, 1);
}
