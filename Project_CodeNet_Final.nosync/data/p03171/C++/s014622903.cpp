#include <bits/stdc++.h>
using namespace std;

#define LEN(x) (int)x.size()
#define ALL(x) x.begin(), x.end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const int MOD = 1'000'000'007;
const double EPS = 0.000'000'001;

inline int fcmp(double x, double y)
{ return (x < y + EPS ? (x < y - EPS ? -1 : 0) : 1);}

const int N = 3010;
pair<ll, ll> dp[N][N];
ll a[N];
bool vis[N][N];
int n;

pair<ll, ll> solve(int l = 0, int r = n - 1)
{
    if(l == r)
    {
        if(n % 2)
            return {a[l], 0LL};
        else
            return {0LL, a[l]};
    }

    if(!vis[l][r])
    {
        vis[l][r] = true;

        ll x1, y1;
        ll x2, y2;

        tie(x2, y2) = solve(l, r - 1);
        tie(x1, y1) = solve(l + 1, r);

        pair<ll, ll> ans;

        if((r - l + 1) % 2 == n % 2)
        {
            if(x1 + a[l] - y1 > x2 + a[r] - y2)
                ans = {x1 + a[l], y1};
            else
                ans = {x2 + a[r], y2};
        }
        else
        {
            if(x1 - a[l] - y1 < x2 - a[r] - y2)
                ans = {x1, y1 + a[l]};
            else
                ans = {x2, y2 + a[r]};
        }

        dp[l][r] = ans;
    }

    return dp[l][r];
}

int main()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cout.precision(10);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    ll x, y;

    tie(x, y) = solve();

    cout << x - y << endl;

    return 0;
}
