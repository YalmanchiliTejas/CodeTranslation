#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  vector<int>aso(N);
  for(int i=0;i<N;i++){
    cin >> aso.at(i);
  }
  
  int high=0;
  int answer=0;
  for(int i=0;i<N;i++){
    if(aso.at(i) >= high){
      answer++;
      high = aso.at(i);
    }
  }
  
  cout << answer << endl;
}