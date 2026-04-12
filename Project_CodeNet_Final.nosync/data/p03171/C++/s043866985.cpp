#include <bits/stdc++.h>
 
#define ll          long long
#define ld          long double
#define pb          push_back
#define pii         pair<int,int> 
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define F         first
#define S           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define mem(x)      memset(x,0,sizeof(x));
#define what_is(x)  cerr << #x << " is " << x << endl;
#define rep(i,a,b)  for(int i=a;i<b;i++)
 
using namespace std;
 
void solve(){
    
    int n;
    cin>>n;

    ll a[n+1];

    rep(i,1,n+1)cin>>a[i];

    ll dp[n+1][n+1];
    
    for(int i=1;i<=n;i++)
        if(n%2)
        dp[i][i]=a[i];
        else
        dp[i][i]=-a[i];

    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            if((n-len)%2==0)
            dp[i][i+len-1]=max(dp[i+1][i+len-1]+a[i],dp[i][i+len-2]+a[i+len-1]);
            else
            dp[i][i+len-1]=min(dp[i+1][i+len-1]-a[i],dp[i][i+len-2]-a[i+len-1]);
        }
    }

    cout<<dp[1][n];

}
 
 
 
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
   
 
    int t=1,i=1;
   // cin>>t;
    
 
    while(t--){
       // cout<<"Case #"<<i++<<": ";
        solve();
    
    }
 
    return 0;
}