#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define mii make_pair<int, int>
#define mll make_pair<ll, ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define all(v) (v).begin(), (v).end()

ofstream out("debug.txt");

const int MxN = 1e5, md = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vl v(n), dp(n, 0);
    for (auto &a : v)
        cin >> a;
    dp[0] = v[0];
    for (int i = 1; i < v.size(); ++i)
        dp[i] = (dp[i - 1] + v[i]) % md;
    ll sum = 0;
    for (int i = 0; i < n - 1; ++i)
        sum = (sum + ((dp[n - 1] - dp[i] + md) % md * v[i]) % md) % md;
    cout << sum << '\n';
}