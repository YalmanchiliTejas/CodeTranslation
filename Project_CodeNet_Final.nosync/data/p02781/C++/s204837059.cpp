#include <bits/stdc++.h>
using namespace std ;
const int N = 200 ;
int dp_less[N][5] ;
int dp_eq[N][5] ;
int a[N] ;
int main()
{
  string s ;
  int k , n ;
  cin >> s >> k ;
  n = s.size() ;
  for(int i = 0 ;i < n ;i ++)
   a[i + 1] = s[i] - '0' ;
  dp_eq[0][0] = 1;
  for(int i = 1; i <= n ;i ++)
   {
     dp_less[i][0] = 1 ;
     dp_eq[i][0] = 0 ;
     for(int j = 1 ;j <= k ;j ++)
      {
        dp_less[i][j] = dp_less[i - 1][j] + 9 * dp_less[i - 1][j - 1] ;
        if(a[i] > 0) dp_less[i][j] += dp_eq[i - 1][j] + (a[i] - 1) * dp_eq[i - 1][j - 1] ;
        if(a[i] != 0)
           dp_eq[i][j] = dp_eq[i - 1][j - 1] ;
        else dp_eq[i][j] = dp_eq[i - 1][j] ;
      }
   }
   cout << dp_less[n][k] + dp_eq[n][k] << endl ;
  return 0 ;
}
