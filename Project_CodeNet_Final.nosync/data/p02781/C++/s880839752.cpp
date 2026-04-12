#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

ll DP[105][5][2];

int main() {
  string N;
  cin>>N;
  int K;
  cin>>K;
  DP[0][1][1] = N[0]-'1';
  DP[0][1][0] = 1;
  for(int i=1;i<N.size();++i) {
    for(int j=0;j<=K;++j) {
      if(N[i]=='0') {
        DP[i][j][0] = DP[i-1][j][0];
        if(j>0) DP[i][j][1] = DP[i-1][j-1][1]*9 + DP[i-1][j][1];
        else DP[i][j][1] = DP[i-1][j][1];
      }
      else {
        if(j>0) DP[i][j][0] = DP[i-1][j-1][0];
        if(j>0) DP[i][j][1] = DP[i-1][j][0] + DP[i-1][j][1] + DP[i-1][j-1][0]*(N[i]-'1') + DP[i-1][j-1][1]*9;
      }
    }
    DP[i][1][1] += 9;
  }
  cout<<DP[N.size()-1][K][0]+DP[N.size()-1][K][1]<<endl;
}

