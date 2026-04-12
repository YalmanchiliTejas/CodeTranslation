#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(v) v.begin(), v.end()
#define sz size()
#define mp make_pair
#define pb push_back
#define rep(p, a, b) for (ll p = a; p < b; p++)
#define rap(p, a, b) for (ll p = a; p <= b; p++)
#define per(p, a, b) for (ll p = a; p >= b; p--)
#define F first
#define S second
using namespace std;

typedef vector<ll> vll;
typedef vector<ld> vld;
typedef pair<ll, ll> pll;

ll n, k, dp[111][5][2];
string u;
vll num;

ll call(ll pos, ll cnt, ll f)
{
    //base case
    if (cnt > k)
        return 0;
    if (pos == n)
    {
        if (cnt == k)
            return 1;
        else
            return 0;
    }
    if (dp[pos][cnt][f] != -1)
        return dp[pos][cnt][f];

    //recur
    ll ret = 0, up;
    if (f == 0)
        up = num[pos];
    else
        up = 9;

    //if(cnt==k)up=0;
    rep(p, 0, up + 1)
    {
        ll ncnt = cnt, nf = f;
        if (f == 0)
        {
            if (p < up)
                nf = 1;
        }
        if (p > 0)
            ncnt++;
        if (ncnt <= k)
            ret += call(pos + 1, ncnt, nf);
    }

    dp[pos][cnt][f] = ret;
    return dp[pos][cnt][f];
}

ll solve(string a)
{
    num.clear();
    rep(p, 0, a.sz) num.pb((a[p] - '0'));
    //reverse(all(num));
    n = num.sz;

    //cout<<n<<" "<<k<<"\n";

    memset(dp, -1, sizeof(dp));
    return call(0, 0, 0);
}

int main()
{
    ll t, i, j, ans;

    //cin>>t;
    t = 1;
    while (t--)
    {
        n = 0;
        cin >> u >> k;
        cout << solve(u);
    }

    return 0;
}