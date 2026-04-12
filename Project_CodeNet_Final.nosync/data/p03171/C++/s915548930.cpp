#include <iostream>


using namespace std;

#define vi vector<int>
#define pb push_back
#define ll long long
#define qi queue<int>
#define vll vector<long long>
#define si set<int>
#define mi map<int,int>
#define mod %
#define frt(i,a,b) for(int i=a;i<b;i++)
#define fre(i,a,b) for(int i=a;i<=b;i++)
#define pair_int pair<int,int>
#define pair_ll pair<ll,ll>
#define pq priority_queue
#define N 100007

ll M = 1000000007;
ll dp[3001][3001];

int main()
{
   int n;
   cin >> n;

   ll a[n+1];
   frt(i,1,n+1)
   	cin >> a[i];
  	
  	for(int sz=1; sz<=n;sz++)
  	{

  		for(int st=1;st+sz-1<=n;st++)
  		{
  			int ed = st+sz-1;
  			int mv;
  			if(n mod 2 == sz mod 2)
  			{
  				if(st==ed)
  					dp[st][sz] = a[st];
  				else
  					dp[st][sz] = max(a[st] + dp[st+1][sz-1], a[ed] + dp[st][sz-1]);
  				
  			}
  			else
  			{
  				if(st==ed)
  					dp[st][sz] = -a[st];

  				else
  					dp[st][sz] = min(-a[st] + dp[st+1][sz-1], -a[ed] + dp[st][sz-1]);
  				
  			}


  		}

  	}

   cout << dp[1][n] << endl;
   return 0;

}

  
