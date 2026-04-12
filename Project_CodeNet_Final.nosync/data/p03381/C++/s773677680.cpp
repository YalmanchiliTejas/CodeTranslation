#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >>N;
  vector<int> A(N,0),B(N,0);
  for(int i=0; i<N; i++){
    int x;
    cin >>x;
    A[i]=x;
  }
  B=A;
  sort(A.begin(), A.end());
  int h=A[N/2], l=A[N/2-1];
  for(int i=0; i<N; i++){
    if(B[i]>=h) cout<<l<<endl;
    else cout<<h<<endl;
  }
}