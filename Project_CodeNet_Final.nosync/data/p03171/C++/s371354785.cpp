
  #include <bits/stdc++.h>
  using namespace std;
  long long MOD=1000000007;
  #define IOS() ios_base::sync_with_stdio(0); cin.tie(0);
  typedef long long ll;
  #define pb push_back
  typedef pair<ll,ll> pi;
  ll dp[4000][4000]={0ll};
  ll a[4000];

ll find (int i, int j)
{
	if(i==j)
		return a[i];
	if(dp[i][j]!=0)
		return dp[i][j];



	dp[i][j]=std::max(a[i]-find(i+1,j),a[j]-find(i,j-1));
	return dp[i][j];
}



int main()
{
  IOS();
 	int n;
 	cin>>n;
 
 	for (int i = 0; i < n; ++i)
 	{
 			cin>>a[i];
 	}
 	
 	

 	for (int i = 0; i < n; ++i)
 	{
 			dp[i][i]=a[i];
 	}

 	cout<<find(0,n-1)<<endl;
  return 0;
}