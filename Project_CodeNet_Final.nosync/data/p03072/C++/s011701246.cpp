#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin >>N;
  vector<int> H(N);
  for(int i = 0; i < N; i++){
    cin >> H.at(i);
  }
  int cnt = 1;
  int tmp = 0;
  for(int i = 1; i < N; i++){
    for(int j = i - 1; j >=0; j--){
      if(H.at(j) <= H.at(i)) tmp++;
    }
    
    if(tmp == i) cnt++;
    
    tmp = 0;
  }
  
  cout << cnt << endl;
}
