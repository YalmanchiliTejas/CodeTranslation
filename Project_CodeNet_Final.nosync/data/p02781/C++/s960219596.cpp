#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; } template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define M 1000000007
#define all(a) (a).begin(),(a).end()
#define rep(i,n) reps(i,0,n)
#define reps(i,m,n) for(int i=(m);i<(n);i++)
int dp[105][4][2];
int main(){
  string s;cin>>s;
  int n=s.size(),k;cin>>k;
  dp[0][0][0]=1;
  rep(i,n)rep(j,4)rep(l,2){
    int nd=s[i]-'0';
    rep(x,10){
      int ni=i+1,nj=j,nl=l;
      if(x!=0)nj++;
      if(nj>k)continue;
      if(nl==0){
        if(x>nd)continue;
        if(x<nd)nl=1;
      }
      dp[ni][nj][nl]+=dp[i][j][l];
    }
  }
  cout<<dp[n][k][0]+dp[n][k][1];
}