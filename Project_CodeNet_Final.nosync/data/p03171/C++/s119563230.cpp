#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(), a.end()
#define pi acos(-1)
#define eps 1e-6
#define inf 1e18

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, 0, 1, -1};
const int maxn = 3001;
const int mod = 1e9 + 7;
const int maxa = 2 * 1e5;

int maxs(int &a, int b) { return a = max(a, b);}
int mins(int &a, int b) { return a = min(a, b);}
int mul(int a, int b) { return a * 1LL * b % mod;}
int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b;}
int sub(int a, int b) { return a >= b ? a - b : a - b + mod;}
int pow(int a, int k)
{
    int res = 1;
    while (k)
    {
        if (k % 2) res = mul(res, a);
        a = mul(a, a);
        k /= 2;
    }

    return res;
}

int inv(int a)
{
    return pow(a, mod - 2);
}

ll dp[maxn][maxn], A[maxn], n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    for (int l = n - 1; l >= 0; --l)
        for (int r = l; r < n; ++r)
            dp[l][r] = l == r ? A[l] : max(A[l] - dp[l + 1][r], A[r] - dp[l][r - 1]);

    cout << dp[0][n - 1];
}
