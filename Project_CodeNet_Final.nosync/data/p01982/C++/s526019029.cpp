#include <iostream>
#include <vector>
using namespace std;

bool is_uruu(int y, vector<int> &A){
  for(size_t i = 0; i < A.size(); ++i){
    if(y%A[i]) continue;
    return (i+1)%2;
  }
  return (A.size()%2 == 0);
}

int main(){
  int n, l, r;
  while(cin >> n >> l >> r, n){
    vector<int> A(n);
    for(int i = 0; i < n; ++i) cin >> A[i];
    int ans = 0;
    for(int i = l; i <= r; ++i){
      if(is_uruu(i,A)) ++ans;
    }
    cout << ans << endl;
  }
  return 0;
}

