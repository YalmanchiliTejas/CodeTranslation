#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)

ll dp[101][2][101];

string ns;
int k;

ll rec(int i, bool less_than_n, int non_zero_cnt) {
  if(dp[i][less_than_n][non_zero_cnt]!=-1) {
    return dp[i][less_than_n][non_zero_cnt];
  }
  if(i==ns.size()) {
    if(non_zero_cnt==k) {
      return 1;
    } else {
      return 0;
    }
  }
  int hd = (int)(ns[i]-'0');
  ll ret = 0;
  // zero
  if(less_than_n) {
    ret += rec(i+1,true,non_zero_cnt);
  } else {
    if(0<hd)
      ret += rec(i+1,true,non_zero_cnt);
    else
      ret += rec(i+1,false,non_zero_cnt);
  }
  // nonzero
  if(less_than_n) {
    repeat(j,1,10) {
      ret += rec(i+1,true,non_zero_cnt+1);
    }
  } else {
    repeat(j,1,hd+1) {
      if(j<hd) {
	ret += rec(i+1,true,non_zero_cnt+1);
      } else {
	ret += rec(i+1,false,non_zero_cnt+1);
      }
    }
  }

  return dp[i][less_than_n][non_zero_cnt] = ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
  cout<<fixed;
  memset(&dp,-1,sizeof(dp));
  cin>>ns>>k;
  cout << rec(0,false, 0) << endl;
  return 0;
}
