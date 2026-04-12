#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,count,a,b,c,d,e,f;
  cin >> N;
  vector<long long> A(N);
  for(int i=0;i<N;i++){cin >> A[i];}
  sort(A.begin(), A.end());
  count=0; a=0; b=0;
  if(N%2==0){
    count+=A[N/2]-A[0];
    for(int i=0;i<N/2-1;i++){
      count+=2*A[N/2+1+i]-A[i]-A[i+1];
    }
  }
  else{
    c=A[0]; d=A[(N-3)/2];  e=A[(N+1)/2]; f=A[(N-1)];
    A[0]=d; A[(N-3)/2]=c;
    for(int i=0;i<(N-1)/2;i++){
      a+=2*A[(N+1)/2+i]-A[i]-A[i+1];
    }
    A[0]=c; A[(N-3)/2]=d;
    A[(N+1)/2]=f; A[(N-1)]=e;
    for(int i=0;i<(N-1)/2;i++){
      b+=A[(N-1)/2+i]+A[(N-1)/2+i+1]-2*A[i];
    }
    count=max(a,b);
  }
  cout << count << endl;
}