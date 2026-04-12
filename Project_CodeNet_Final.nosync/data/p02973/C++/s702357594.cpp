#include <bits/stdc++.h>
using namespace std;
 
int main(){ 
  int N;
  vector<int64_t> A(100010);

  cin >> N;
  for(int i=0; i<N; i++) cin >> A[i];

  
  vector<int64_t> cur_max; cur_max.push_back(A[0]);
  int ans = 1; 

  for(int i=1; i<N; i++){
    if(A[i] <= cur_max[cur_max.size()-1]){
      cur_max.push_back(A[i]);
      ans++;
    } else if(A[i] > cur_max[0]){
      cur_max[0] = A[i];
    } else {
      int p = upper_bound(cur_max.begin(), cur_max.end(), A[i], greater<int>()) - cur_max.begin();
      cur_max[p] = A[i];
    }    
  }

  cout << ans << endl;

}