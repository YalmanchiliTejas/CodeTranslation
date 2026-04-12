#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int N;
  cin >> N;
  vector<int64_t> A(N);
  rep(i, N){
    cin >> A.at(i);
  }
  
  int64_t ans = 0;
  
  int64_t sum_rest = 0;
  for(int i = 0; i <N; i++){
    sum_rest += A.at(i);
    sum_rest %= 1000000007LL;
  }
  
  rep(i, N-1){
    if(sum_rest >= A.at(i)){
      sum_rest -= A.at(i);
    }else{
      sum_rest += 1000000007LL - A.at(i);
    }
    ans += A.at(i) * sum_rest % 1000000007LL; 
    ans %= 1000000007LL;
  }//end rep i 
  cout << ans << endl;
}
