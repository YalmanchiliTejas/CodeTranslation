#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >>N;
  int h[N]; for(int i=0;i<N;i++){cin >>h[i];}
  
  int r=0;
  for(int i=0;i<N;i++){
    bool flag = true;
    for(int j=0;j<i;j++){
      if(h[j]>h[i]){
        flag = false;
        break;
      }
    }
    r += flag;
  }
  cout << r << endl;
  
}