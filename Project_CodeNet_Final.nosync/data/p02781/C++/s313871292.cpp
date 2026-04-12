#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define vpli vector<pair<long long, int>>
#define deb(x) cout << "deb " << #x << " " << x << endl;
#define all(x) x.begin(), x.end()
ll MOD = 1e9 + 7;
const int INF = 2e9 + 10;
int n;
int k;
vi s;
vector<vvi> dp(2, vvi(105, vi(5, -1)));

int f(bool fill, int curr, int count)
{
    if(count > k) return 0;
    if (curr == n && count != k)
        return 0;
    if (curr == n && count == k)
        return dp[fill][curr][count] = 1;
    if (dp[fill][curr][count] != -1)
        return dp[fill][curr][count];
    int last = (fill ? s[curr] : 9);
    int ans = 0;
    for (int i = 0; i <= last; i++)
    {
        if(i == 1 && curr == 0)
        {
            //deb((fill && (i == last)));
            //deb((curr + 1));
            //deb((count + (i > 0)))
        }
        ans += f(fill && (i == last), curr + 1, count + (i > 0));
    }
    //cout << fill << " " << curr << " " << count << " " << ans << " \n";
    return dp[fill][curr][count] = ans;
}

void solve()
{
    string t;
    cin >> t >> k;
    for (char c : t)
    {
        s.pb(c - '0');
    }
    n = s.size();
    cout << f(1, 0, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}