#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,X,ans=0,tall;
  cin>>N>>X;
  tall=X;
  for(int i=1;i<N;i++){
    cin>>X;
    if(X>=tall)
      ans++;
    tall=max(tall,X);
    }
  cout<<ans+1;
  }