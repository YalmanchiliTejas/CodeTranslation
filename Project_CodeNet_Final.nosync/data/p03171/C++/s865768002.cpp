//Utkarsh-raj

#include<bits/stdc++.h>

#define ll long long int
#define vc vector
#define mod 100000000007
#define mp make_pair
#define pb push_back
#define nl cout<<endl;
#define ff first
#define ss second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ifstream myFile("task.in");
    if(!myFile.fail())
    {
        assert(freopen("task.in", "r", stdin));
    }

    ll n, sum = 0;
    cin>>n;

    ll arr[n+1];
    for(ll i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }

    vector<vector<ll> > dp(n, vector<ll> (n, 0));

    for(ll i=0; i<n; i++){
        dp[i][i] = arr[i];
    }

    for(ll i=0; i<n-1; i++){
        dp[i][i+1] = max(arr[i], arr[i+1]);
    }

    for(ll len = 3; len <= n; len++){
        for(ll i=0; i<=n - len; i++){
            ll j = i + len - 1;

            // cout<<i+2<<" "<<j<<" "<<i<<" "<<j-2<<" "<<i-1<<" "<<j-1<<endl;
            dp[i][j] = max(arr[i] + min(dp[i+2][j], dp[i+1][j-1]), arr[j] + min(dp[i][j-2], dp[i+1][j-1]));
        }
    }

    ll x = dp[0][n-1];
    ll y = sum - x;

    cout<<(x - y)<<endl;

    return 0;
}
