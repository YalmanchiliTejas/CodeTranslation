#include<bits/stdc++.h>
using namespace std;

int64_t patie(int64_t i, int64_t j){
  if(i == 0 && j == 1){
    return 1;
  }
  else if(i == 1 && j == 1){
    return 0;
  }
  else if(i == 1 && j <= 5){
    return min(j-1,(int64_t)3);
  }
  else if(j == 1){
    return 0;
  }
  else if(j < pow(2,i+1)-1){
    return patie(i-1, j-1);
  }
  else if(j == pow(2,i+1)-1){
    return patie(i-1,pow(2,i+1)-3) + 1;
  }
  else if(j == pow(2,i+2)-3){
    return patie(i-1,pow(2,i+1)-3)*2 + 1;
  }
  else{
    int64_t x = j - 2 - (pow(2,i+1) - 3);
    return patie(i-1,pow(2,i+1)-3) + 1 + patie(i-1,x);
  }
}

int main(){
  int64_t N, X;
  cin >> N >> X;
  cout << patie(N,X) << endl;
}