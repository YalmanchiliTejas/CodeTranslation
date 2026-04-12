#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,ans=0;
  cin>>N;
  vector<int> ar(N);
  for(int i=0;i<N;i++){
    cin>>ar[i];
  }
  
  
  int jibunh=0,flg=1;
  for(int i=0;i<N;i++){
    jibunh=ar[i];
    flg=1;
          for(int j=0;j<i;j++){
                  if (jibunh<ar[j]){
                    flg=0;
                    break;
                  }
          }
    ans+=flg;
  }
  
  cout<<ans<<endl;
  return 0;
}