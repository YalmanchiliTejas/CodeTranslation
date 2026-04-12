#include <bits/stdc++.h>
using namespace std;

int main(){
int ans=0 ,max,N ;
  cin>>N;
  vector<int>vec(N);
  for(int i=0;i<N;i++){
  cin>>vec.at(i);
  }
  for(int i=0;i<N;i++){
  if(i==0){
  max=vec.at(i);
    ans++;
  }
    else{
    if(max<=vec.at(i)){
    max=vec.at(i);
      ans++;
    }
    }
  }
cout<<ans<<endl;
}