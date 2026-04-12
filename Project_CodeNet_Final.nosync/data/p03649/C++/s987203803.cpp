#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  
  long long cnt=0;
  long long A[N];
  long long temp;
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  while(1){
    sort(A,A+N);
    if(A[N-1]<N){
      cout<<cnt<<endl;
      return 0;
    }
    temp=1+(A[N-1]-N)/N;
    cnt+=temp;
    A[N-1]-=N*temp;
    for(int i=0;i<N-1;i++){
      A[i]+=temp;
    }
  }

  
  return 0;
}

  