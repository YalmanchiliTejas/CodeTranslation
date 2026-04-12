#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,i,j;
  cin>>n;
  vector<int64_t> a(n+1);
  vector<vector<int64_t>> dp(n+1,vector<int64_t>(2));
  for(i=1;i<=n;i++) cin>>a.at(i);
  dp.at(1).at(0)=0;
  dp.at(1).at(1)=a.at(1);
  dp.at(2).at(0)=0;
  dp.at(2).at(1)=max(a.at(1),a.at(2));
  for(i=3;i<=n;i++){
    if(i%2==1) {
      dp.at(i).at(0)=max(dp.at(i-1).at(1),dp.at(i-2).at(0)+a.at(i));
      dp.at(i).at(1)=dp.at(i-2).at(1)+a.at(i);
    }
    else if(i%2==0) {
      dp.at(i).at(0)=max(dp.at(i-1).at(0),dp.at(i-2).at(0)+a.at(i));
      dp.at(i).at(1)=max(dp.at(i-1).at(1),dp.at(i-2).at(1)+a.at(i));
    }
  }
  if(n%2==0) cout<<dp.at(n).at(1)<<endl;
  else if(n%2==1) cout<<dp.at(n).at(0)<<endl;
}