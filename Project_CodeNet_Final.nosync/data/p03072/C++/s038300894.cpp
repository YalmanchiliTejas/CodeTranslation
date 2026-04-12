#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int A[N];
  int maxA=0;
  int cnt=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    maxA=max(maxA,A[i]);
    if(A[i]>=maxA){
      cnt++;
    }
  }
  cout<<cnt<<endl;
  return 0;
}
