//In the name of God

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;

#define int ll

const int N = 3e3+10 , mod = 1e9+7;

int dp[N][N] , a[N] , n;
bool mk[N][N];

int go(int l , int r){
   if(mk[l][r])
      return dp[l][r];
   mk[l][r] = true;
   int x = 1;
   if((r - l + 1) % 2 != n % 2)
      x = -1;
   if(l == r)
      return dp[l][r] = x * a[l];
   if(x == 1)
      return dp[l][r] = max(a[l] + go(l + 1 , r) , a[r] + go(l , r - 1));
   else
      return dp[l][r] = min(-a[l] + go(l + 1 , r) , -a[r] + go(l , r - 1));
}

int32_t main(){
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   cout << fixed << setprecision(9);
   cin >> n;
   for(int i = 0 ; i < n ; i++)
      cin >> a[i];
   cout << go(0 , n - 1);
   return 0;
}
