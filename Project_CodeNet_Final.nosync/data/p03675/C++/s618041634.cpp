#include <bits/stdc++.h>
#define N 200010
using namespace std;
int A[N];

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++)cin>>A[i];
  
  deque <int> B;
  B.push_back(A[0]);
  for(int i=1;i<n;i++){
    if((n-i)%2==0) B.push_back(A[i]);
    else B.push_front(A[i]);
  }
  
  for(int i=0;i<B.size();i++){
    if(i)cout<<" ";
    cout<<B[i];
  }
  cout<<endl;

    
  
  return 0;
}
