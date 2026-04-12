//
#include<bits/stdc++.h>

using namespace std;

#define PB push_back
#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int MOD = 1000000007;
const int INF = 1000000007;
const int MAXN = (int)2e5+1;

ll pref[MAXN], arr[MAXN], dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    pref[0] = arr[0];
    for(int i=2; i<n; i+=2)
    {
        pref[i] = pref[i-2] + arr[i];
    }

    for(int i=1; i<n; i++)
    {
        if(i&1)
        {
            dp[i] = arr[i] + dp[i-2];
            dp[i] = max(dp[i], pref[i-1]);
        }
        else
        {
            dp[i] = dp[i-2] + arr[i];
            dp[i] = max(dp[i], dp[i-1]);
        }
    }
    cout << dp[n-1];
    return 0;
}
