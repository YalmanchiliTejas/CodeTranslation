#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,Max =1,Ans =0;
  vector<int> H(100);
  cin >> N;
  
  for(int i =0;i < N;i++){
    cin >> H.at(i);
  }
  for(int j =0;j <N;j++){
    if(H.at(j) >= Max){
      Max = H.at(j);
      Ans += 1;
    }
  }
  cout << Ans << endl;
}
  
  
