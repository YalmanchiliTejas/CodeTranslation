#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound

int main(){
  ll N,S;
  cin>>N>>S;
  VL A(N);
  rep(i,N) cin>>A[i];
  ll mod=998244353;
  ll dp[3001][3001][3]={};
  dp[0][0][0]=1;
  rep(i,N){
    rep(j,3001){
      (dp[i+1][j][0]+=dp[i][j][0])%=mod;
      (dp[i+1][j][1]+=dp[i][j][0]+dp[i][j][1])%=mod;
      (dp[i+1][j][2]+=dp[i][j][0]+dp[i][j][1]+dp[i][j][2])%=mod;
      if(j+A[i]<=S){
        (dp[i+1][j+A[i]][1]+=dp[i][j][0]+dp[i][j][1])%mod;
        (dp[i+1][j+A[i]][2]+=dp[i][j][0]+dp[i][j][1])%mod;
      }
    }
  }
  cout<<dp[N][S][2]<<endl;
}