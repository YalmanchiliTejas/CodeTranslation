#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound

int main(){
  int N;
  cin>>N;
  VL A(N);
  rep(i,N) cin>>A[i];
  VVL dp(N+2,VL(N%2+2));
  rep(i,N+2) rep(j,N%2+2) dp[i][j]=-1001001001001001;
  dp[0][0]=0;
  rep(i,N+1){
    rep(j,N%2+2){
      if(j<N%2+1) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
      if(i<N) dp[i+2][j]=max(dp[i+2][j],dp[i][j]+A[i]);
    }
  }
  cout<<dp[N+1][N%2+1]<<endl;
}

