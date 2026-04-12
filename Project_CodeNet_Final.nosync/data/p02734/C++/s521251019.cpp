#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

const int mod = 998244353;
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


int n, s;
int a[3000];
int dp[3000][3000];

int f(int i, int sum)
{
    if (sum > s)
        return 0;
    if (sum == s)
        return n - i + 1;
    if (i == n)
        return 0;
    int& sol = dp[i][sum];
    if (sol != -1)
        return sol;
    return sol = add(f(i + 1, sum), f(i + 1, sum + a[i]));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    memset(dp, -1, sizeof dp);
    int sol = 0;
    for (int i = 0; i < n; ++i)
        adds(sol, mul(i + 1, f(i + 1, a[i])));
    cout << sol;
}
