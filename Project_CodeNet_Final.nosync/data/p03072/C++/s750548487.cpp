#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 1;
  vector<int>vec(N);
  for(int i=0; i < N; i++){
    cin >> vec[i];
  }
  for(int i = 1; i<N; i++){
    bool boo = true;
    for(int j = 0;j<i; j++){
      if(vec[i] < vec[j]){
        boo =  false;
      }
    }
   if(boo){ 
     ans++;
   }
  }
  cout << ans << endl;
}
