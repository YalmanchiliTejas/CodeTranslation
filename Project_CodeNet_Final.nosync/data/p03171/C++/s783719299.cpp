    //Catchharsh
    #include<bits/stdc++.h>
    #define ll long long int 
    #define ld long double
    #define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    #define F first
    #define S second
    #define pb push_back
    #define endl '\n'
    const ll MOD = 1e9+7;
    const ll INF = 1011111111;
    const ll LLINF = 1000111000111000111LL;
    const ld EPS = 1e-10;
    const ld PI = 3.14159265358979323;
    using namespace std;
    ll power (int x,int n)
    {
        if(n==0)
        return 1;
        else if(n%2==0)
        return power((x*x),n/2);
        else
        return x*power((x*x),(n-1)/2); 
    }
    vector<ll> seve;
    void  seveprime()
    {
      int prime[1000000]={0};
      for(int i=2;i*i<1000000;i++)
       {
        if(prime[i]==0)
         {
      	  for(int j=i*2;j<=1000000;j+=i)
           prime[j]=1;
         }
       }
       for(int i=2;i<=1000000;i++)
       {
       	if(prime[i]==0)
       		seve.pb(i);
       }
    }
    pair<ll,ll>  dp[3001][3001];
    int main()
    {   
         IOS; 
         ll n,m,i,j,k;
         cin>>n;
         vector<ll> v(n+1);
         for(i=1;i<=n;i++)
         	cin>>v[i];
         for(i=0;i<=n;i++)
         {
         	for(j=0;j<=n;j++)
         	{
         		dp[i][j].F=-1;
         		dp[i][j].S=-1;
         	}
         }
         for(i=1;i<=n;i++)
            {dp[i][i].F=v[i];dp[i][i].S=0;}
         // for(i=1;i<n;i++)
         // {
         // 	for(j=1;j<=n;j++)
         // 	{
         // 		if(j<i)
         // 			continue;
         //       if(i==j)
         //       	continue;
         // 		dp[i][j].F=max(dp[i+1][j].S+v[i],dp[i][j-1].S+v[j]);
         // 		if(dp[i][j].F==(dp[i+1][j].S+v[i]))
         // 			dp[i][j].S=dp[i+1][j].F;
         // 		else
         // 			dp[i][j].S=dp[i][j-1].F;
         // 		//cout<<dp[i][j].F<<" "<<dp[i][j].S<<endl;
         // 	}
         // }
       for(i=1;i<=n;i++)
       {
       	  for(j=1;j<=n;j++)
       	  {
       	  	k=i+j;
       	  	if(k<=n)
       	  	{
       	  	dp[j][k].F=max(dp[j+1][k].S+v[j],dp[j][k-1].S+v[k]);
       	  	  if(dp[j][k].F==dp[j+1][k].S+v[j])
       	  	  	dp[j][k].S=dp[j+1][k].F;
       	  	  else
       	  	  	dp[j][k].S=dp[j][k-1].F;
       	    }
       	  }
       }
         //   for(i=1;i<=n;i++)
         // {
         // 	for(j=1;j<=n;j++)
         // 	{
         // 		cout<<dp[i][j].F<<" "<<dp[i][j].S<<"     ";
         // 	}
         // 	cout<<endl;
         // }
         cout<<dp[1][n].F-dp[1][n].S;

     
    }