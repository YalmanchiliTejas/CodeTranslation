#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int> H(N);
  for(int i=0;i<N;i++)
    cin>>H.at(i);
  int ans=1;
  int Max=H.at(0);
  for(int i=1;i<N;i++){
  if(Max<=H.at(i)){
  Max=H.at(i);
    ans++;
  }
  
  }cout<<ans<<endl;
   return 0;
}