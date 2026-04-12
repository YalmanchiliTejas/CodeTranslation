#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<db, db> pdd;
typedef vector<int> vi;
#define m1 make_pair
#define in insert
#define pb push_back
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"
inline ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

const ll mod = 1e9 + 7;
const int N = int(3e5) + 999;
#define int long long int
#define inf 1e18

string s;
int d;

void add(int &a, int b)
{
    a = (a + b) % mod;
}

int32_t main()
{
    IOS;

    cin >> s;
    cin >> d;
    vector<vector<int>> dp(d, vector<int>(2, 0));
    dp[0][0] = 1;
    for (int i = 0; i < s.size(); ++i)
    {
        vector<vector<int>> ndp(d, vector<int>(2, 0));
        for (int sum = 0; sum < d; sum++)
        {
            for (int flag : {0, 1})
            {
                for (int dig = 0; dig <= 9; ++dig)
                {
                    if (dig > s[i] - '0' and !flag)
                        break;
                    add(ndp[(sum + dig) % d][flag || (dig < (s[i] - '0'))], dp[sum][flag]);
                }
            }
        }
        dp = ndp;
    }

    int ans = dp[0][0] + dp[0][1];
    ans %= mod;
    --ans;
    if (ans < 0)
        ans += mod;
    cout << ans;

    return 0;
}