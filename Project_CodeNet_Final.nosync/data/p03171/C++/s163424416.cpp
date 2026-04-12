#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
int n = 3005;
vector<int> a(n);
vector<vector<ll>> dp(n,vector<ll>(n,0));
vector<vector<bool>> flg(n,vector<bool>(n,false));

ll dfs(int l,int r){
    if(l==r){
      if((n-1)%2==0){
        flg.at(l).at(r) = true;
        return dp.at(l).at(r) = a.at(r);
      }else{
        flg.at(l).at(r) = true;
        return dp.at(l).at(r) = -a.at(l);
      }
    }
    if(!flg.at(l).at(r-1)){
      dp.at(l).at(r-1) = dfs(l,r-1);
      flg.at(l).at(r-1) = true;
    }
    if(!flg.at(l+1).at(r)){
      dp.at(l+1).at(r) = dfs(l+1,r);
      flg.at(l+1).at(r) = true;
    }
  if((n-1-r+l)%2 == 0){
    dp.at(l).at(r) = max(dp.at(l).at(r-1)+a.at(r),dp.at(l+1).at(r)+a.at(l));
  }else{
    dp.at(l).at(r) = min(dp.at(l).at(r-1)-a.at(r),dp.at(l+1).at(r)-a.at(l));
  }
  return dp.at(l).at(r);
}                         
 
int main() {
  cin >> n;
  rep(i,n) cin >> a.at(i);
  cout << dfs(0,n-1) << endl;
 
  return 0;
}


