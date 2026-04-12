#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

lli n, l, r, tot, a[3005], dp[3005][3005][2] ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++) cin>> a[i], dp[i][i][0]=a[i], tot+=a[i] ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j+i<=n ; j++)
        {
          l=j ; r=j+i ;
          dp[l][r][0]=max(dp[l+1][r][1]+a[l], dp[l][r-1][1]+a[r]) ;
          dp[l][r][1]=min(dp[l+1][r][0], dp[l][r-1][0]) ;
        }
    cout<< 2*dp[1][n][0]-tot ;
  }
