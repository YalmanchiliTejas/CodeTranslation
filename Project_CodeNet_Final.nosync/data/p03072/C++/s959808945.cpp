#include<bits/stdc++.h>
#define  pb push_back
#define  xx first
#define  yy second
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
int h,n;
int dp[1001];
int v[4000],cost[4000];
int ans = 1e-9;
/*
int go(int i,int sum){

        if(dp[i][sum]!=-1) return dp[i][sum];

       dp[i][sum] =min(val[i]+go(i+1,W-a[i]),go(i+1,W));
       return dp[i][sum];
}
*/
void go(int i,int x, int y ){

     ans = max(ans,x-y);
    if(i>n){
      return ;
    }
    go(i+1,v[i]+x,cost[i]+y);
    go(i+1,x,y);
    return;
}
 int main()
{
   // fast;

    int n;
    cin >> n;
    int a[n+10];
    for(int i = 1; i<=n; i++) cin >> a[i];
    int ans = 0,mx = 0;
    for(int i = 1; i<=n; i++){
        mx = max(a[i],mx);
        if(mx >a[i])continue;
         ans++;
    }
    cout << ans << '\n';

   return 0;
}
