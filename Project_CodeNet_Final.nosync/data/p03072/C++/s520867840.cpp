#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N;
  cin>>N;
  
  vector<int> H(N);
  
  for(int i=0;i<N;i++){
    cin>>H[i];
  }
  
  int ans=0;
  
  int Max=0;
  
  for(int i=0;i<N;i++){
    if(H[i]>=Max) ans++;
    Max=max(Max,H[i]);
  }
  
  cout<<ans<<endl;
  
  
  
  return 0;
}
