#include <bits/stdc++.h>
using namespace std;

// dp[len][left]: data[left, left+ len) における max (手番側の得点)-(非手番側の得点) とおくと
// dp[len+1][left]= max(data[left]- dp[len][left+1], data[left+len]- dp[len][left])
// 以上を len in [1,N) についてインライン更新していく。
int main(){
  size_t N;
  cin >> N;

  vector<int64_t> data(N);
  for(size_t i=0; i<N; i++){
    cin >> data.at(i);
  }

  vector<int64_t> dp= data;
  while(dp.size() > 1){
    size_t len= N- dp.size()+ 1;
    vector<int64_t> dp_next;
    for(int left=0; left+len<N; left++){
      int64_t elem= max(data.at(left)- dp.at(left+1), data.at(left+len)- dp.at(left));
      dp_next.emplace_back(elem);
    }

    dp= dp_next;
  }

  cout << dp.at(0) << endl;
}