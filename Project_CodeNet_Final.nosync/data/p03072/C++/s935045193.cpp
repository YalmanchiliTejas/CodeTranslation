
#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  int i;
  int n=0;
  cin >> N;
  vector<int> H(N);
  int max=0;
    for(i=0;i<N;i++){
      cin >> H.at(i);
    }
  for(i=0;i<N;i++){
    if(H.at(i)>=max){
      n++;
      max=H.at(i);
    }
  }
  cout << n << endl;
}
      
      
  
  