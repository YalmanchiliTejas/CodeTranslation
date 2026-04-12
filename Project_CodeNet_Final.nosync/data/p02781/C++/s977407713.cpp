#include <bits/stdc++.h>
using namespace std;

int main(){
  string N;
  int K;
  cin >> N >> K;

  vector<vector<long long>> dp(N.size()+1,vector<long long>(5,0));
  //dp.at(0).at(0)=1;
  int count=0;
  for(int i=0;i<N.size();i++){
    for(int j=0;j<=K;j++){
      if(j>0) dp.at(i+1).at(j)=dp.at(i).at(j) + dp.at(i).at(j-1)*9;
      else  dp.at(i+1).at(j)=dp.at(i).at(j);
    }
    if(N.at(i)=='0')  continue;
    if(count<5) dp.at(i+1).at(count)++;
    if(count+1<5) dp.at(i+1).at(count+1)+=(N.at(i)-'0')-1;
    count++;
  }
  if(count==K)  dp.at(N.size()).at(K)++;
  cout << dp.at(N.size()).at(K) << endl;

  return 0;
}
