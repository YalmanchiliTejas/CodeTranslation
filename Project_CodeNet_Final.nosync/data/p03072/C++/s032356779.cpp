#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N;
  
  vector<int> S(N);
  int num = 1;
  
  for(int i = 0;i < N;++i){
    cin >> S[i];
  }

  for(int i = 1;i < N;++i){
    int num2 = 0;
    for(int k = 0;k < i;++k){
      if(S[k] > S[i]){
        num2++;
      }
    }
    if(num2 == 0){
      num++;
    }
  }
  cout << num << endl;
}
  
