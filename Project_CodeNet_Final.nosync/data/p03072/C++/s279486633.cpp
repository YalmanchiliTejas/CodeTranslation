#include<bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N;
  vector<int> H(N);
  
  for(int i=0;i<N;i++) {
    cin >> H.at(i);
  }
  
  int count=0;
  int max=H.at(0);
  for(int i=0;i<N;i++){
    if(max<=H.at(i)) count++;
    if(max<H.at(i)) max=H.at(i);
  }
  
  cout << count << endl;
  
  return 0;
}
    