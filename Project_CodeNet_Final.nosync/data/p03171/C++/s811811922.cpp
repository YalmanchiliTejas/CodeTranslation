#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[3003] , pr[3003];
int dp[3003][3003];


int f(int i, int j) {
  if (dp[i][j]) 
    return dp[i][j];
  int r;
  if (i == j) 
    r = a[i];
  else if (i + 1 == j) 
    r = max(a[i], a[j]);
    
  else
    r = max(  min(f(i+1, j-1), f(i+2, j)) + a[i], min(f(i, j-2), f(i+1, j-1)) + a[j]);
  dp[i][j] = r;
  return r;
}


main()
{
	int n , sum = 0;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld" , &a[i]);
		pr[i] = pr[i-1] + a[i];
		sum += a[i];
	}
	
	cout << f(1 , n) * 2 - sum << endl;
	
}
