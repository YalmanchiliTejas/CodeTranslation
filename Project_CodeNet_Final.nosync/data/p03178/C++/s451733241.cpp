#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;
int dp[2][100][2];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string num;
  int d;
  cin>>num>>d;
  int mod=1e9+7;
  int l=num.length();
  dp[0][0][1]=1;
  rep(i,l)
  {
    int ni=num[i]-'0';
    int no=i&1,ne=1-no;
    rep(j,d){dp[ne][j][0]=0,dp[ne][j][1]=0;}
    rep(j,d)
    {
      rep(k,10)
      {
        dp[ne][(j+k)%d][0]+=dp[no][j][0];
        dp[ne][(j+k)%d][0]%=mod;
      }
      rep(k,ni)
      {
        dp[ne][(j+k)%d][0]+=dp[no][j][1];
        dp[ne][(j+k)%d][0]%=mod;
      }
      dp[ne][(j+ni)%d][1]+=dp[no][j][1];
      dp[ne][(j+ni)%d][1]%=mod;
    }
  }
  cout<<((ll)mod+dp[l&1][0][0]+dp[l&1][0][1]-1)%mod<<endl;
  return 0;

}
