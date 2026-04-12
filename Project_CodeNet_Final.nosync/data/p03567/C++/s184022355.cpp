#include<bits/stdc++.h>
using namespace std;
int main(){
  string S; cin>>S;
  int J=0;
  for(int i=0; i<S.size()-1; i++){
    if(S.at(i)=='A'&&S.at(i+1)=='C')
      J++;
    else continue;
  }
  if(J!=0)
    cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}