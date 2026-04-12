#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define pb push_back
#define mp make_pair
#define f(i,a,n) for(int i=a ; i<(int)n ; i++)
#define rf(i,n,a) for(int i=n ; i>=a ; i--)
#define F first
#define S second
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()
#define fast ios:: sync_with_stdio(false),cin.tie(nullptr);

typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;

const int inf = 1e9;
const int inf64 = 1e18;
const int MOD = inf + 7;
int dp[3001][3001][2];
int a[3001];
int solve(int l , int r , int turn) {
   if(l == r) return (turn ? -a[l] : a[l]);
   int &res = dp[l][r][turn];
   if(res != -1)  return res;
   res = 0;
   if(turn == 0) {
      res = max(solve(l+1 , r , 1) + a[l] , solve(l , r-1 , 1) + a[r]);
   }
   else {
      res = min (solve(l+1 , r , 0) - a[l] , solve(l , r-1, 0) - a[r]);
   }
   return res;
}
int32_t main(){
   fast;
   int n;
   cin >> n;
   f(i,1,n+1)  cin >> a[i];
   memset(dp , -1 , sizeof(dp));
   cout << solve(1,n,0);
}