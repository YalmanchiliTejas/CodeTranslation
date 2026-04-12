#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
#define print(x) cerr << (#x) << "is "<< x << "\n"
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 3000 + 10;

int a[N],dp[N][N][2],n;
 
int dfs(int i,int j,int v){
   if(j < i) return 0;
   if(i<1 or i>n or j<1 or j>n) return 0;
   int &ans = dp[i][j][v];
   if(ans != -1){
      return ans;
   }
   if(v){
      return ans = min(dfs(i+1,j,1^v)-a[i],dfs(i,j-1,1^v)-a[j]);
   }else{
      return ans = max(dfs(i+1,j,1^v)+a[i],dfs(i,j-1,1^v)+a[j]);
   }
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   // #ifndef ONLINE_JUDGE
   //    freopen("input.txt", "r", stdin);
   //    freopen("output.txt", "w", stdout);
   // #endif
   cin >> n;
   f(i,1,n+1){
      f(j,1,n+1){
         f(k,0,2){
            dp[i][j][k] = -1;
         }
      }
   }
   f(i,1,n+1){
      cin >> a[i];
   }
   cout << dfs(1,n,0) << '\n';
   return 0;
}