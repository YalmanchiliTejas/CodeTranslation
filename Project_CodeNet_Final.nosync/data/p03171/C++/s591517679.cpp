#include <bits/stdc++.h>
using namespace std;

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define f           first
#define s          second
#define sz(x)       (int)x.size()
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rep0(a,n)  for(int i=0;i<n;i++)cin>>a[i]
#define si(x)       cin>>x
#define sii(x,y)    cin>>x>>y
#define siii(x,y,z) cin>>x>>y>>z
#define ahell   998244353
#define hell 1000000007
#define N 1000001
#define fl 1.0000000000
//#define mod 998244353
#define cntbit(a) __builtin_popcountl(a)
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
main()
{
  ios
int n,m,i;
int j;
int u,v,q;
int test=1;
//si(test);

while(test--)
{
  cin>>n;
  int a[n];
  for(i=0;i<n;i++)
    cin>>a[i];
  int dp[n][n];
  for(i=0;i<n;i++)
  {
    dp[i][i]=a[i];
  }
  for(int l=2;l<=n;l++)
  {
    for(i=0;i+l<=n;i++)
    {
        int t=max(a[i]-dp[i+1][i+l-1],a[i+l-1]-dp[i][i+l-2]);
        dp[i][i+l-1]=t;
    }
  }

  cout<<dp[0][n-1];

}

}
