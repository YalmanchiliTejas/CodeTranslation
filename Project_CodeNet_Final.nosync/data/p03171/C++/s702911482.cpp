#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define ff first
#define ss second
#define endl '\n'
#define MAX INT_MAX
#define MIN INT_MIN
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007
#define pb push_back
#define sz(a) (int)((a).size())
#define all(a) a.begin(),a.end()
#define loopf(i,a,b) for(int i = a;i < b;i++)
#define loopb(i,a,b) for(int i = a;i >= b;i--)
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair< int,int > pii;


int32_t main()
{
    fast

   int test=1;
  // cin>>test;

  while(test--)
  {
  
 int n;
 cin>>n;
vvi dp(n,vi (n,0));
int a[n];
for(int i=0;i<n;i++)cin>>a[i];

  for(int l=n-1;l>=0;l--)
    for(int r=l;r<n;r++)
    {
      if(l==r)dp[l][r]=a[l];
      else dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
    }

    cout<<dp[0][n-1];

  //while loop ending 
  }



return 0;
}