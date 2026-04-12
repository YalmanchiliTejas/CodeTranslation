#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define mod (int)(1e9+7)
#define endl '\n'
#define MAXI (int)(3e17+10)
#define N 100005


// Driver code to test above functions
int32_t main()
{
    
     
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

 
    
   	int n;
   	cin >> n;

   	int a[n+1];
   	for(int i=1;i<=n;i++)
   		cin >> a[i];

   	int pos[n+1] = {0}, dp[n+1] = {0};

   	//cout << a[4] << endl;
   	
   	pos[1] = a[1];
   	for(int i=2;i<=n;i++)
   		pos[i] = pos[i-2] + a[i];

   	for(int i=2;i<=n;i++)
   	{
   		if(i%2==1)
   			dp[i] = max(dp[i-1], dp[i-2] + a[i]);
   		else
   			dp[i] = max(pos[i-1], dp[i-2] + a[i]);
   		//cout << dp[i] << " " << pos[i] << endl;
   	}

   	cout << dp[n];

   	
    
    
    return 0;
 
} 