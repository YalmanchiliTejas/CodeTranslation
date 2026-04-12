#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  for(int i = 0;i<N;i++){
    cin >> H[i];
  }
  int max = 0;

  for(int i = 0;i<N;i++){
    int count = 0;
    for(int j=0;j<i;j++){
      if(H[i] < H[j]){
        break;
      }
      count++;
    }
    if(count == i){
      max+=1;
    }
  }

  cout << max <<endl;
}

