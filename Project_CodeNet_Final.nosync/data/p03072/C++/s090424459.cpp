#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<int> H(N);
  for(int i=0;i<N;i++){
    cin>>H[i];
  }
  
  int ans=1;
  
  
  for(int i=1;i<N;i++){
    bool res=true;
    for(int j=0;j<=i;j++){
      if(H[i]<H[j]){
        res=false;
      }
    }
    if(res){
      ans++;
  }
  }
  
  cout<<ans<<endl;
}