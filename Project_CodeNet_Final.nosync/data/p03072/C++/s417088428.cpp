#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  for(int i=0;i<N;i++){
    cin >> H.at(i);
  }
  
  int K = H.at(0);
  int answer = 0;
  
  for(int i=0;i<N;i++){
    if(K <= H.at(i)){
      K = H.at(i);
      answer++;
    }
  }
  
  cout << answer << endl;
}