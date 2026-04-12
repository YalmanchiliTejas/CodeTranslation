#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[4000];
ll dp[3001][3001][2];

ll f(ll pos , ll n , ll i , ll j)
{
    if(i > j)
    {
       // cout << i << " " << j << "\n";
       return 0;
    }
   // cout << i << " " << j << "\n";
    if(dp[i][j][pos%2] != -1)
    return dp[i][j][pos%2];
    ll ans = -1e18;
    if((pos%2))
    {
        ans = max(ans , a[i] + f(pos+1 , n , i+1  , j));
        ans = max(ans , a[j] + f(pos+1 , n , i , j-1)); 
    }
    else
    {
        ans = 1e18;
       //  cout << i << " " << j << "  " << ans << "\n";
        ans = min(ans, -a[i] + f(pos+1 , n , i+1 , j));
        ans = min(ans , -a[j]+f(pos+1 , n , i , j-1));
       //  cout << i << " " << j << "  " << ans << "\n";
    }
    dp[i][j][pos%2] = ans;
    return ans;
}

int main() {
    
   ll n;
   cin >> n;
   for(ll i = 1 ; i <=  n ; i++)
   cin >> a[i];
   for(ll i = 0 ; i <= 3000 ; i++)
   {
       for(ll j = 0 ; j <= 3000 ; j++)
       {
           dp[i][j][0] = -1;
           dp[i][j][1] = -1;
       }
   }
    //cout << "hello" << "\n";
   cout <<  f(1 , n , 1 , n);

}
