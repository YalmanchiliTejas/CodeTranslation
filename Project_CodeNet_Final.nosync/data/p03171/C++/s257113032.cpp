#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define loops(i, s, n) for (ll i = s; i < n; i++)
#define loop(i, n) for (ll i = 0; i < n; i++)
#define eps 1e-9
#define loopitr(mp) for (auto itr = mp.begin(); itr != mp.end(); itr++)
#define init(arr, n, val)       \
    for (ll i = 0; i < n; i++) \
        arr[i] = val;
#define even_set 0xAAAAAAAA ... 1010101010
#define odd_set 0x55555555 ... 01010101
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define vall(v) v.begin(), v.end()
#define mkp make_pair
#define ret return
#define cont continue
#define nl endl
#define ff first
#define ss second
#define cnt_bits __builtin_popcount
#define init(arr, n, val)       \
    for (ll i = 0; i < n; i++) \
        arr[i] = val;
const ll mod = 1000000007;
ll dp[3001][3001];

ll sum(ll i, ll j, ll ps[]){
    ret ps[j] - ((i-1>=0) ? ps[i-1] : 0);
}

int main()
{

    fastio;
    ll n, k;
    cin >> n;
    ll arr[n];
    ll ps[n];
    for (ll &x : arr)
    {
        cin >> x;
    }

    for (ll i = 0; i < n; i++)
    {
        dp[i][i] = arr[i];
        ps[i] = arr[i] + ((i - 1 >= 0) ? ps[i - 1] : 0);
    }

    for (ll len = 2; len <= n; len++)
    {
        for (ll i = 0; i <= n - len; i++)
        {
            ll j = i + len - 1;
            
            if (len == 2)
            {
                dp[i][j] = max(arr[i], arr[j]);
            }
            else
            {
                dp[i][j] = max(arr[i] + sum(i+1, j, ps) - dp[i + 1][j] , arr[j] + sum(i, j-1, ps) - dp[i][j - 1]);
            }
        }
    }

    cout << 2*dp[0][n - 1] - ps[n-1] << endl;
}