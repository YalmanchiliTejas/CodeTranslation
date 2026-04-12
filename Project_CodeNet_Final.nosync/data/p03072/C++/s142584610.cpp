#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int>A(N);
  for (int i=0; i<N; i++)cin>>A[i];
  int MAX=A[0];
  int cnt=0;
  for (int i=0; i<N; i++){
    if (MAX<A[i])MAX=A[i];
    if (MAX<=A[i])cnt++;
  }
  cout<<cnt<<endl;
}

  
  
