#include <bits/stdc++.h>
using namespace std;

#define VIC ios::sync_with_stdio(0);cin.tie(0);ios_base::sync_with_stdio(0);
#define wtf(s) freopen((s), "w", stdout)
#define rff(s) freopen((s), "r", stdin)
#define pi (2 * acos(0))
typedef long double ld;
typedef long long ll;
typedef complex<ld> point;
#define endl '\n'
#define matrix vector<vector<ll>>
#define EPS 1e-9
#define X real()
#define Y imag()
#define vec(a, b) ((b) - (a))
#define dot(a, b) ((conj(a) * (b)).real())
#define cross(a, b) ((conj(a) *(b)).imag())
#define lengthsqr(v) (dot(v, v))
#define length(v) ((ld)hypot((v).Y, (v).X))
#define same(a, b) (lengthsqr(vec(a, b)) < EPS)

const int N = 1e4 + 5, inf = 2e9, mod = 1e9 + 7;

// Base case:
// states:
// transitions:

string s;
int d, dp[N][2][2][102];

int solve(int idx, bool less, bool notZero, int sum)
{
    if (idx == s.size())
        return notZero && sum % d == 0? 1: 0;
    if (dp[idx][less][notZero][sum] != -1)
        return dp[idx][less][notZero][sum];
    int ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        bool newNotZero = notZero;
        if (i > 0)
            newNotZero = true;
        if (less)
            ans += solve(idx + 1, less, newNotZero, (sum + i) % d);
        else
        {
            if (i < s[idx] - '0')
                ans += solve(idx + 1, true, newNotZero, (sum + i) % d);
            else if (i == s[idx] - '0')
                ans += solve(idx + 1, false, newNotZero, (sum + i) % d);
        }
        ans %= mod;
    }
    return dp[idx][less][notZero][sum] = ans;
}

int main()
{
    VIC
    memset(dp, -1, sizeof dp);
    cin >> s >> d;
    cout << solve(0, false, false, 0);
    return 0;
}
