#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll optimalStrategyOfGame(ll* arr, ll n) 
{ 
    // Create a table to store solutions of subproblems 
    ll table[n][n]; 
  
    // Fill table using above recursive formula. Note  
    // that the table is filled in diagonal fashion (similar 
    // to http:// goo.gl/PQqoS), from diagonal elements to 
    // table[0][n-1] which is the result. 
    for (ll gap = 0; gap < n; ++gap) { 
        for (ll i = 0, j = gap; j < n; ++i, ++j) { 
  
            // Here x is value of F(i+2, j), y is F(i+1, j-1) and 
            // z is F(i, j-2) in above recursive formula 
            ll x = ((i + 2) <= j) ? table[i + 2][j] : 0; 
            ll y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0; 
            ll z = (i <= (j - 2)) ? table[i][j - 2] : 0; 
  
            table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z)); 
        } 
    } 
  
    return table[0][n - 1]; 
} 
  
// Driver program to test above function 
int main() 
{
	ll n;
	cin >> n;
	ll arr[n],s=0,i;
	for(i=0;i<n;i++)
	{
		cin >> arr[i]; 
		s+=arr[i];
	}
	ll ans = optimalStrategyOfGame(arr, n); 
		ll y = s-ans;
    cout << ans-y << "\n"; 
    return 0; 
}