#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int64_t X;
  cin>>X;
  int64_t sum=0;

  while(X>0){
    if(X<=pow(2,N+1)-2){
      --N;
      --X;
    }
    else if(X==pow(2,N+1)-1){
      sum += int64_t(pow(2,N));
      break;
    }
    else if(X==pow(2,N+2)-3){
      sum += int64_t(pow(2,N+1))-1;
      break;
    }
    else{
      X -= int64_t(pow(2,N+1))-1;
      sum += int64_t(pow(2,N));
      --N;
    }
  }

  cout<<sum<<endl;

}