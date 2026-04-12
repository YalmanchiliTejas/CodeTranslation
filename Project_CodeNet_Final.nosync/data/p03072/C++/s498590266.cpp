#include<bits/stdc++.h>
using namespace std;

int main(){
  int i,N,max,x,h;
  cin >> N;
  max = 0;
  x = 0;
  for(i=0;i<N;i++){
    cin >> h;
    if(h>=max){
      max = h;
      x++;
    }
  }
  cout << x << endl;
  return 0;
}