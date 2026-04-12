#include<bits/stdc++.h>


#define ll long long int
#define pb push_back
#define F first
#define S second 
#define f(i,n) for(ll i = 0; i < n; i++)
using namespace std;
ll solve(ll n, ll coins[])

{

    //matrix to store results

    ll dp[n][n];

 

    //dp[i][j]=maximum amount you can definitely win if you move first with available coins[i...j]

 

    ll i,j;

 

    //initialization

    //if we have only one coin and we have to move first, we will pick that coin

    for(j=0;j<n;j++)

    {

        dp[j][j]=coins[j];

    }

 

    //if we have only two coins and we have to move first, we will pick the coin of higher value

    for(j=0;j<n-1;j++)

        dp[j][j+1]=max(coins[j],coins[j+1]);

 

    //we will calculate results for a row of i coins 

    for(i=2;i<n;i++)

    {

        //we will calculate result dp[j][j+i]

        for(j=0;j+i<n;j++)

        {

            ll x=coins[j]+min(dp[j+2][j+i],dp[j+1][j+i-1]);

            ll y=coins[j+i]+min(dp[j+1][j+i-1],dp[j][j+i-2]);

 

            dp[j][j+i]=max(x,y);

        }

    }

 

    return dp[0][n-1];

}

 
int main()
{
 
     #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     #endif
     //soe();
      ll n; cin>>n;
      ll a[n];
      ll sum = 0;
      ll x;
      f(i,n) 
      {
          cin>>x;
          sum += x;
          a[i] = x;
      }
      ll i = 0, j = n-1;
      
       
      //cout<<sum;
      if(n == 1)
      {
        cout<<a[0];
        return 0;
      }

      ll z = solve(n,a);
      ll o = sum - z;
      cout<<(z-o)<<endl;

     return 0;
}