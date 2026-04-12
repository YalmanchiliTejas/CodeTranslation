#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;vector<int>X(26,50);
  for(int i=0;i<n;i++){
    string S;cin>>S;
    for(int j=0;j<26;j++){
      int x=count(S.begin(),S.end(),char('a'+j));
      X.at(j)=min(X.at(j),x);
    }
  }
  for(int i=0;i<26;i++)for(int j=0;j<X.at(i);j++)cout<<char('a'+i);
  cout<<endl;
}