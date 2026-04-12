 #include <bits/stdc++.h>
    using namespace std;
    #define ll long long 
    #define ull unsigned long long 
    #define ld long double
    #define fi first
    #define se second
    #define pb push_back
    #define mp make_pair
    ll mod=1e9+7;
 
     ll a[200005];
       ll b[200005];
 
     ll idx[100005][2];
    // ll cnt[200005];
     ll pre[200005];
    // ll end[200005];
     map<ll,ll> m;
 
    bool comp(const pair<ll,ll>& a, const pair<ll,ll>& b){
      return (a.fi-a.se)>(b.fi-b.se);
    }
 
    bool revcomp(const pair<ll,ll>& a, const pair<ll,ll>& b){
      return (a.fi)>(b.fi);
    }
 
 
    ll ceil11(ll a, ll b){
      if(a%b!=0)return a/b+1;
      else return a/b;
    }
    ll power(ll a,ll b,ll n){ll ans=1;while(b>0){if(b%2==1)ans=(ans*a)%n;a=(a*a)%n;b/=2;}return ans;}
 
    ll count1=0;
 
 
    ll gcd(ll a, ll b){
      //if(a<b)swap(a,b);
      if(b==0)return a;
      return gcd(b,a%b);
    }
 
  ll primepos(ll fact, ll p) 
  { 
      ll res = 0; 
      while (fact > 0) {         
          res += fact / p; 
          fact /= p;  
      } 
    
      return res; 
  } 
 
  // void dfs(ll n, ll p){
  //   if(vis[n]!=0){
  //     return;
  //   }
  //   else{
  //     vis[n]=1;
  //     b[n]=p;
  //     for(int i=0;i<v[n].size();i++){
  //       dfs(v[n][i],p);
  //     }
  //   }
  ll ceil1(ll a,ll b){
    return a/b;
  }

   
   int main(){

      ios::sync_with_stdio(0);
      int n;
      cin>>n;
      for(int i=1;i<=n;i++){
        cin>>a[i];
      }
      ll dp[n+1][n+1][2];
      memset(dp,0,sizeof dp);
      for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
          if(i==j){
            dp[i][j][0]=a[i];
            dp[i][j][1]=-1*a[i];
          }
         
          //cout<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
        }
      }
      for(int j=1;j<=n;j++){
        for(int i=j-1;i>=0;i--){
          if(i==0||j==0){
            dp[i][j][0]=0;
            dp[i][j][1]=0;
          }
          else{
            dp[i][j][0]=max(a[i]+dp[i+1][j][1],a[j]+dp[i][j-1][1]);
            dp[i][j][1]=min(-1*a[i]+dp[i+1][j][0],-1*a[j]+dp[i][j-1][0]);
          }
        }
      }
      cout<<dp[1][n][0]<<endl;

      return 0;
} 