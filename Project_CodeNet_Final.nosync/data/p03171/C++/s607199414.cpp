//Utkarsh-raj

#include<bits/stdc++.h>

#define ll long long int
#define vc vector
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define nl cout<<endl;
#define ff first
#define ss second

using namespace std;

const ll MAX = 1e9+5;


int main()
{
    ifstream myFile("task.in");
    if(!myFile.fail())
    {
        assert(freopen("task.in", "r", stdin));
    }

    ll n;
    cin>>n;

    ll arr[n+1];
    for(ll i=1; i<=n; i++){
        cin>>arr[i];
    }

    pair<ll, ll> dp[n+1][n+1];

    for(ll i=0; i<=n; i++){
        for(ll j=0; j<=n; j++){
            dp[i][j] = mp(0, 0);
        }
    }

    for(ll i=1; i<=n; i++){
        dp[i][i] = mp(arr[i], 0);
    }

    for(ll l=2; l<=n; l++){
        for(ll i=1; i<=n-l+1; i++){
            ll s = i, e = i+l-1;

            ll a1, a2;
            a1 = arr[s] + dp[s+1][e].ss;
            a2 = dp[s+1][e].ff;

            pair<ll, ll> p1 = mp(a1, a2);

            a1 = arr[e] + dp[s][e-1].ss;
            a2 = dp[s][e-1].ff;

            pair<ll, ll> p2 = mp(a1, a2);

            dp[s][e] = max(p1, p2);
        }
    }

    cout<<(dp[1][n].ff - dp[1][n].ss)<<endl;

    return 0;
}
