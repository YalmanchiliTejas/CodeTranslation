#include <bits/stdc++.h>
using namespace std;
 
int abs(int x, int y) {
  if (x < y) {
    return y-x;
  }
  else{
    return x-y;
  }
}
int main(){
  int N;
  cin >>N;
  vector<int> H(N);
  for(int i =0;i<N; i++){
    cin >> H.at(i);
  }
  int count = 1;
  for(int i =1;i<N;i++){
    bool anal= true;
    for(int j =0;j<i ;j++){
      if(H.at(i) <H.at(j)){
        anal = false;
      }
    }
    if(anal){
      count ++;
    }
  }
  cout <<count <<endl;

  
}