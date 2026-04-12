#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,X,M; cin >> N >> X >> M;
  vector<long long> A(M);
  vector<int> R(M,-1);
  int start=-1,last=-1;
  for(int i=0; i<M; i++){
    if(i==0){
      A[i]=X;
      R[X]=i;
    }else{
      A[i]=(A[i-1]*A[i-1])%M;
      if(R[A[i]]<0){
        R[A[i]]=i;
      }else{
        start=R[A[i]];
        last=i;
        break;
      }
    }
  }
  if(start<0){
    start=R[(A[M-1]*A[M-1])%M];
    last=M;
  }
  long long sum=0;
  for(int i=0; i<start; i++){
    sum+=A[i];
  }
  long long loopsum=0;
  for(int i=start; i<last; i++){
    loopsum+=A[i];
  }
  sum+=((N-start)/(last-start))*loopsum;
  int residue=(N-start)%(last-start);
  for(int i=start; i<start+residue; i++){
    sum+=A[i];
  }
  cout << sum << endl;
}