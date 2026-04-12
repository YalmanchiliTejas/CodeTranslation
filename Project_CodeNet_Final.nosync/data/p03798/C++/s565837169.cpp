#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

bool check(string s, string ans, int n)
{
    if (s[n - 1] == 'o')
    {
        if (ans[n - 1] == 'S')
        {
            return (ans[n - 2] == ans[0]);
        }
        else
        {
            return (ans[n - 2] != ans[0]);
        }
    }
    else
    {
        if (ans[n - 1] == 'S')
        {
            return (ans[n - 2] != ans[0]);
        }
        else
        {
            return (ans[n - 2] == ans[0]);
        }
    }
    return false;
}

bool check2(string s, string ans, int n)
{
    if (s[0] == 'o')
    {
        if (ans[0] == 'S')
        {
            return (ans[1] == ans[n - 1]);
        }
        else
        {
            return (ans[1] != ans[n - 1]);
        }
    }
    else
    {
        if (ans[0] == 'S')
        {
            return (ans[1] != ans[n - 1]);
        }
        else
        {
            return (ans[1] == ans[n - 1]);
        }
    }
    return false;
}

string koutiku(string s, int n, string ans)
{
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] == 'o')
        {
            if (ans[i] == 'S')
            {
                ans += ans[i - 1];
            }
            else
            {
                ans += (ans[i - 1] == 'S' ? 'W' : 'S');
            }
        }
        else
        {
            if (ans[i] == 'S')
            {
                ans += (ans[i - 1] == 'S' ? 'W' : 'S');
            }
            else
            {
                ans += ans[i - 1];
            }
        }
    }
    return ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string s, ans;
    cin >> n >> s;
    // 1番目がS,2番目がWであると仮定
    ans = "SW";
    ans = koutiku(s, n, ans);
    if (check(s, ans, n) && check2(s, ans, n))
    {
        cout << ans << endl;
        return 0;
    }
    // 1番目がS,2番目がSであると仮定
    ans = "SS";
    ans = koutiku(s, n, ans);
    if (check(s, ans, n) && check2(s, ans, n))
    {
        cout << ans << endl;
        return 0;
    }
    // 1番目がW,2番目がSであると仮定
    ans = "WS";
    ans = koutiku(s, n, ans);
    if (check(s, ans, n) && check2(s, ans, n))
    {
        cout << ans << endl;
        return 0;
    }
    // 1番目がW,2番目がWであると仮定
    ans = "WW";
    ans = koutiku(s, n, ans);
    if (check(s, ans, n) && check2(s, ans, n))
    {
        cout << ans << endl;
        return 0;
    }
    cout << "-1" << endl;
}