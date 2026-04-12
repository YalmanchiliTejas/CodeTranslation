#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
  long long N;
  cin>>N;
  long long X,M;
  cin>>X>>M;
  long long answer=0;
  long long A=X;
  if(N>M){
  long long rot[100000];
  for(int i=0;i<M;i++){
    rot[i]=A;
    answer+=A;
    A=(A*A)%M;
  }
  long long roop=1;
  long long S=rot[M-roop];
  while(A!=rot[M-roop]){
    roop++; S+=rot[M-roop];
  }
  answer+=((N-M)/roop)*S;
  for(long long i=0;i<(N-M)%roop;i++){
    answer+=A; A=(A*A)%M;
  }
  }
  else{
    for(int i=0;i<N;i++){
      answer+=A; A=(A*A)%M;
    }
  }
  cout<<answer<<endl;
  
  return 0;
}