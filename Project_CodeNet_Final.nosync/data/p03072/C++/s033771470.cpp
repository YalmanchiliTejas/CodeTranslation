#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,Hmax=0,N,count=0;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> H;
    if(Hmax<=H){
      count++;
      Hmax=H;
    }
  }
  cout << count << endl;
  return 0;
}