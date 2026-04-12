#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=998244353;
int INF=100100100100100;
int pol[3010][6020];
int a[3010];
signed main(){
  int n,s;cin>>n>>s;
  int ans=0;
  rep(i,n)cin>>a[i];
  pol[0][0]=1;
  rep(i,n){
    rep(j,s+1){
      (pol[i+1][j]+=pol[i][j])%=MOD;
      if(j+a[i]<=s)(pol[i+1][j+a[i]]+=pol[i][j])%=MOD;
    }
    pol[i+1][0]++;
    (ans+=pol[i+1][s])%=MOD;
  }
 
  cout<<ans<<endl;
  return 0;
}