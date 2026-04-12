#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,ii,iii)for(int i=ii;i<iii;i++)
#define RFOR(i,ii,iii)for(int i=iii-1;i>=ii;i--)
#define OUT(a)cout<<a<<endl
#define ALL(s) s.begin(),s.end()
#define PB push_back
#define mset(a,b) memset(a,b,sizeof(a))
#define ANS(a) OUT(res.size());for(auto i:a)cout<<i<<" ";ENDL
#define PRINT(a,init,end) FOR(i,init,end) cout<<a[i]<<" ";ENDL
#define PRINTV(a) for(auto i:a)cout<<i<<" ";ENDL
#define F first
#define S second

const int N=3000+15;
int n,k;
ll a[N],dp[N][N][3];
ll solve(int i,int j,int c) {
  ll res;
  if(i==j)res = c*a[i];
  else {
    if(dp[i][j][c+1]!=-1)return dp[i][j][c+1];
    if(c>0) {
      res=max(c*a[i]+solve(i+1,j,-c),
                 c*a[j]+solve(i,j-1,-c));
    } else {
      res=min(c*a[i]+solve(i+1,j,-c),
                 c*a[j]+solve(i,j-1,-c));
    }
  }
  dp[i][j][c+1]=res;
  //cout<<i<<" "<<j<<" "<<c<<" : "<<res<<endl;
  return res;
}

int main() {
  mset(dp,-1);
  ios::sync_with_stdio(false);
  cin>>n;
  ll s=0;
  FOR(i,0,n)cin>>a[i],s+=a[i];
  cout<<solve(0,n-1,1)<<endl;
  //cout<<solve(0,n-1,1)-s<<endl;
}