#include<bits/stdc++.h>
#define N 3050
#define int long long
#define pb push_back
#define x first
#define y second
#define all(v) v.begin(),v.end()
#define coffee prince
#define sz(a) (int)a.size()
#define ll long long
#define SIZE N
using namespace std;
int n,s;
int dp[N],ar[N];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>s;
    for(int i=0;i<n;i++)
        cin>>ar[i];
    int ans = 0;
  	int mod = 998244353;
    for(int i=0;i<n;i++){
        for(int j=s-ar[i];j>0;j--){
            dp[j+ar[i]] += dp[j];
          dp[j+ar[i]]%=mod;
        }
        dp[ar[i]]+=i+1;
      	dp[ar[i]]%=mod;
      ans += dp[s];ans%=mod;
    }
 	cout<<ans;
        return 0;
}
