#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define DBG(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
const ll p = 1e9+7;
const ll INF = 1LL << 60;

ll dp[3333][3333];
ll n,a[3333];
ll rec(int l,int r){
  if(dp[l][r]!=INF)return dp[l][r];
  if(n%2!=(r-l)%2)return dp[l][r]=max(rec(l+1,r)+a[l],rec(l,r-1)+a[r]);
  return dp[l][r]=min(rec(l+1,r)-a[l],rec(l,r-1)-a[r]);
}

int main(){
  cin>>n;
  fill_n(*dp,3333*3333,INF);
  for(int i=0;i<n;i++){
    cin>>a[i];
    dp[i][i]=a[i]*(n%2?1:-1);
  }
  cout<<rec(0,n-1)<<endl;
  return 0;
}
