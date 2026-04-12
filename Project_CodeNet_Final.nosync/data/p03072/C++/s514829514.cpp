#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >>N;
  vector<int> H(N);
  rep(i, N) cin >> H[i];
  int sum = 1;
  for(int i=1;i<N;i++){
    bool flag = true;
    for(int j=0;j<i;j++){
      if (H[j]>H[i]) flag = false;
    }
    if (flag){
    sum++;
    }
  }
  
  cout << sum << endl;
  
  
  return 0;
}
