#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(i,x,n)  for(int i=x;i<n;i++)
#define FASTIO cin.tie(0); cout.tie(0);


int main()
{
	FASTIO;
	ll n;
	 cin>>n;
	 vector<ll>vect(n);
	 f(i,0,n)
	  cin>>vect[i];



	  ///dp[i][j] -> will denote x-y for the array starting
	  //with i and ending at j
	  ll dp[n][n] ={};

	  for(int i=0;i<n;i++)
        dp[i][i]=vect[i];

      //we just need to fill the upper triangle
      //as both upper and lower will be mirror images.
      ll times=n-1;
      for(ll diff=1;diff<=n-1;diff++,times--)
      {
          ll row=0,col=row+diff;
          for(int i=1;i<=times;i++)
          {
              dp[row][col]= max(vect[row]-dp[row+1][col],vect[col]-dp[row][col-1]);
              row++;
              col++;
          }
      }

      /*for(int i=0;i<n;i++)
      {
          for(int j=0;j<n;j++)
            cout<<dp[i][j]<<" ";
          cout<<"\n";
      }*/

	  cout<<dp[0][n-1]<<"\n";

	return 0;
}











