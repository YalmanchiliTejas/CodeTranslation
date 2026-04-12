#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ms memset
#define MOD 1000000007
#define sp fixed<<setprecision
#define sz sizeof
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod2=998244353;
ll fpow(ll x,ll y){x=x%MOD;ll sum=1;while(y){if(y&1)sum=sum*x;sum%=MOD;y=y>>1;x=x*x;x%=MOD;}return sum;}
ll inv(ll a,ll m=MOD){ll c=m;ll y=0,x=1;if(m==1)return 0;while(a>1){ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=c;return x;}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    ll a[n];
    ll sum=0;
    for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];}
    ll dp[n][n]; // dp(i,j) denotes the maximum sum player starting at array i...j can get
    memset(dp,0,sizeof(dp));
    // initialized everything with 0
    // if there are 2 elements only player who starts should obviously pick the greater elemennt

    for(int i=n-1;i>=0;i--)
    for(int j=i;j<n;j++)
    {
      if(i==j)
      dp[i][j]=a[i];
      else if(j==(i+1))
      dp[i][j]=max(a[i],a[j]);
  //    if((j-i)<2)continue;
      //0...1...2
      // we have already filled this above

      // now comes the main part
      // he has two options: either pick i or j
      // option 1: picks i : now array remaining is i+1.....j
      // and its b's turn now player b will make choice to maximize his own score
      // therefore he will pick  the max of dp[i+2,,,,j] by taking i+1 or dp[i+1.....j-1] by taking j
      // so we will be left with min(dp[i+2][j], dp[i+1][j-1]);

      // option 2 player a picks j: now the remaining aray is i...j-1;
      // and its player b's turn , player be will max for himself , so we will be left with min
        //i..i+1 i+2..j-2...j-1..j.
      else
      dp[i][j]=max(a[i]+min(dp[i+2][j],dp[i+1][j-1]),a[j]+min(dp[i+1][j-1],dp[i][j-2]));

    }
    cout<<2*dp[0][n-1]-sum<<"\n"; // will give the result for player A
    // hence player B will be left with S-dp[0][n-1]
    // result is dp[0][n-1]-(s-dp[0][n-1])
    // 2*dp[0][n-1]-s
    // got it?
    //cout<<dp[n-1][n-1]<<"\n";

  /*  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++)
    cout<<dp[i][j]<<' ';
    cout<<"\n";}*/
}
