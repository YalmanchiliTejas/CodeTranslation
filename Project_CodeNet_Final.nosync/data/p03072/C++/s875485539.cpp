#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  
  vector <int> H(N);
  for(int i=0;i<N;i++){
    cin>>H[i];
  }
  
  int ans=0;
  
  for(int i=0;i<N;i++){
    bool yuri=true;
    for(int j=0;j<i;j++){
      if(H[j]>H[i]){
        yuri=false;
      }
    }
    if(yuri){
      ans++;
    }
  }
  cout<<ans<<endl;
}
  