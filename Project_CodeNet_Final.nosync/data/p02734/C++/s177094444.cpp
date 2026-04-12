 #include<bits/stdc++.h>
/* 
*    coder :: ATUL_PANDEY_2608
*        >>> INDIA <<<
*/
using namespace std;

// #define  part ..
#define listi vector<int > 
#define listll vector<long long >
#define pii pair<int ,int > 
#define pll pair<long long ,long long >
#define heap priority_queue<long long >

#define pb(a) push_back(a)
#define mod 998244353
#define maxx 200006
#define ll long long 
#define quick   ios_base::sync_with_stdio(NULL),cin.tie(0);
#define rep(i,a,b) for(int i=a;i<b;i++)
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// #define test int t;cin>>t;while(t--)
// end of #define 

// define globals ...





int Main()
{

ll dp[3030][3030][3];
int a[3030];

    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++)cin >> a[i];
    dp[0][0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            (dp[i+1][j][0] += dp[i][j][0]) %= mod;
            (dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
            (dp[i+1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) %= mod;
            if(j + a[i] <= k){
                (dp[i+1][j+a[i]][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
                (dp[i+1][j+a[i]][2] += dp[i][j][0] + dp[i][j][1]) %= mod;
            }
        }
    }
    cout << dp[n][k][2] << endl;







  
  return 0;
}























// main function..
int main(){

   
    Main();
    
    
}
