#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int MOD = 1000000007, MAX = 2000000007, MAXN = 100005;
const ll LLMAX = 200000000000000007;

ll solve(int n,vector<ll> a)
{
    vector<ll> dp(n+1,0);
    vector<ll> pref(n+1,0);
    pref[1] = a[0];
    for(int i=2; i<=n; i++)
        pref[i] = pref[i-2] + a[i-1];
    for(int i=2; i<=n; i++)
    {
        if(i%2)
            dp[i] = max(dp[i-2] + a[i-1], dp[i-1]);
        else
            dp[i] = max(dp[i-2] + a[i-1], pref[i-1]);
    }
    return dp[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    vector<ll> a;
    for(int i=0; i<n; i++)
    {
        ll ele;
        cin>>ele;
        a.push_back(ele);
    }
    cout<<solve(n,a);
	return 0;
}