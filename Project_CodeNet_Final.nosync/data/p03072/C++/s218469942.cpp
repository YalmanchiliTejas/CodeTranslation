#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  vector<int> H(N);
  for(int i=0;i<N;i++){
  	cin >> H.at(i);
  }
  
  int Answer=1;
  int flag=0;
  
  for(int i=1;i<N;i++){
  flag=0;
  for(int j=0;j<i;j++){
  	if(H.at(i)<H.at(j)){ 
    flag=1;
    break;
    }
  }
    if(flag==0) Answer++;
  }
  
  cout << Answer << endl;
  
  return 0;
}
