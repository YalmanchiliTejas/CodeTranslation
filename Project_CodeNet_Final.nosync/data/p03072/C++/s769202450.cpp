#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, a, max, C;
  cin >> N;
  vector<int> H(N);
  for(int i=0; i<N; i++){
    cin >> H.at(i);
  }
  
  C = 0;
  max = H.at(0);
  
  for(int i=0;i<N;i++){
    a = H.at(i)-max;
    if(a>=0){
      C++;
      max = H.at(i);
    }
  }
  cout << C << endl;
}