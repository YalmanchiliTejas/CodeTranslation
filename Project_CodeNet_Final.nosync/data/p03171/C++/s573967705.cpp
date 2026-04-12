
// Medha's code  :


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dd;
#define fastio ios_base:: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define INF 0x3f3f3f3f3f
#define MOD 1000000007

int main() {

    fastio;

    ll n,j,k=1;
    vector<ll> a(3005);
    vector<vector<ll>> dp(3005 , vector<ll> (3005));

    cin >> n;

    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for( ll i = 1; i <= n; i++)
    {
        if(n%2 == 0)
        {
            dp[i][i] = -a[i];
        }

        else dp[i][i] = a[i];
    }


    for(  j = 2 ; j <= n ; j++)
    {
        k = j;
        ll i = 1;
        while( i <= (n-j+1) && j <= n)
        {
            ll h = k-i+1;
           if(( n - h) % 2 == 0)
           {
               dp[i][k] = max(dp[i+1][k] + a[i] , dp[i][k-1] +a[k]);
           }

           else {
               dp[i][k] = min( dp[i+1][k] - a[i] , dp[i][k-1] -a[k]);
           }

           i++;
           k++;
        }
    }

//    for( ll i = 1; i <= n ; i++)
//    {
//        for( ll b = 1 ; b <= n ; b++)
//        {
//            cout << dp[i][b] <<" ";
//        }
//        cout << "\n";
//    }

    cout<< dp[1][n];



    return 0;
}
