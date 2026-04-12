#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double dd;
const int N = 1e5+5;
const dd eps = 1e-8;
const int mod = 998244353;

int n,s,dp[3005],a[3005],now,ans;

int main(){
  ios::sync_with_stdio(false);
  // freopen("input.txt","r",stdin);
  cin>>n>>s;
  while(n--){
    cin>>now;
    dp[0]++;
    for(int i = s-now;i >= 0;i--){
      dp[i+now] = (dp[i+now]+dp[i])%mod;
    }
    ans = (ans+dp[s])%mod;
  }
  cout<<ans<<endl;
  return 0;
}
