#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define reset(x, y) memset(x, y, sizeof(x))
#define ii pair<int, int>
#define task ""
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}
const long long oo = 1e9 + 7;
long long dp[10000][100][2];
string k,a;
int d;
vector<int> digit;
void get(string s, vector<int> &digit)
{
    for (int i = 0; i < s.size(); ++i)
        digit.push_back(s[i] - '0');
}
long long calc(int idx, int muda, int tight)
{
    if (idx == digit.size())
       { if (muda == 0)
            return 1;
            return 0;
       }
    if (dp[idx][muda][tight] != -1)
        return dp[idx][muda][tight];
    long long res = 0;
    int lmt = (tight) ? digit[idx] : 9;
    for (int i = 0; i <= lmt; ++i)
    {
        int newtight = (digit[idx] == i) ? tight : 0;
        res = (res + calc(idx + 1, (muda + i) % d, newtight)) % oo;
    }
    dp[idx][muda][tight] = res;
    return res;
}
long long solve(string s)
{
    digit.clear();
    reset(dp,-1);
    get(s, digit);
    return calc(0, 0, 1);
}
///----------------------------------------------------------------------------------///
int main()
{
    fast;
    cin >> k;
    cin >> d;
    a="0";
    cout << 1LL * ((solve(k)-1+oo)%oo) << "\n";
}