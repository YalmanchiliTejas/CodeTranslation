#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> H(N);
  for(int i=0;i<N;i++){
    cin >> H.at(i);
  }
  
  int count = 1;
  
  for(int i=1;i<N;i++){
    int x=0;
    for(int j=0;j<i;j++){
      if(H.at(i)<H.at(j)){
        x=1;
        break;
      }
    }
    if(x==0){
      count++;
    }
  }
  
  cout << count << endl;
 
}