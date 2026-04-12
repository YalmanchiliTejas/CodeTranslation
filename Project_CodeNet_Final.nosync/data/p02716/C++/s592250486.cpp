//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1e9;
const ll LINF = ll(1e18);
const int MOD = 1000000007;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define debug(v)          \
    cout << #v << ":";    \
    for (auto x : v)      \
    {                     \
        cout << x << ' '; \
    }                     \
    cout << endl;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
//cout<<fixed<<setprecision(15);有効数字15桁
//-std=c++14
//-std=gnu++17
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int n;
vector<ll> a;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        a.push_back(temp);
    }
    if (n % 2)
    {
        vector<vector<ll>> dp(n, vector<ll>(3, -LINF));
        dp[0][0] = a[0];
        dp[1][1] = a[1];
        if (n >= 3)
        {
            dp[2][2] = a[2];
        }
        for (int i = 2; i < n; i++)
        { //マイナスがあるから取り得ではない
            if (dp[i - 2][0] != -LINF)
                chmax(dp[i][0], dp[i - 2][0] + a[i]);
            if (dp[i - 2][1] != -LINF)
                chmax(dp[i][1], dp[i - 2][1] + a[i]);
            if (dp[i - 2][2] != -LINF)
                chmax(dp[i][2], dp[i - 2][2] + a[i]);
            if (i != 2)
            {
                if (dp[i - 3][0] != -LINF)
                    chmax(dp[i][1], dp[i - 3][0] + a[i]);
                if (dp[i - 3][1] != -LINF)
                    chmax(dp[i][2], dp[i - 3][1] + a[i]);
            }
            if(i>=4){
                if (dp[i - 4][0] != -LINF)
                    chmax(dp[i][2], dp[i - 4][0] + a[i]);
            }
        }
        ll ans = -LINF;
        rep(i, 2)
        {
            rep(j, 3)
            {
                if(i==0&&j==0)continue;
                chmax(ans, dp[n - 1 - i][j]);
            }
        }
        if(n!=2)
        chmax(ans,dp[n-3][0]);
        cout << ans << "\n";
    }
    else
    {
        vector<vector<ll>> dp(n, vector<ll>(2, -LINF));
        dp[0][0] = a[0];
        dp[1][1] = a[1];
        for (int i = 2; i < n; i++)
        { //マイナスがあるから取り得ではない
            if (dp[i - 2][0] != -LINF)
                chmax(dp[i][0], dp[i - 2][0] + a[i]);
            if (dp[i - 2][1] != -LINF)
                chmax(dp[i][1], dp[i - 2][1] + a[i]);
            if (i != 2)
            {
                if (dp[i - 3][0] != -LINF)
                    chmax(dp[i][1], dp[i - 3][0] + a[i]);
            }
        }
        ll ans = -LINF;
        rep(i, 2)
        {
            rep(j, 2)
            {
                chmax(ans, dp[n - 1 - i][j]);
            }
        }
        cout << ans << "\n";
    }
}
