#include<bits/stdc++.h>
using namespace std;
int main(){
  int m,i,j,k,l;
  string x;
  cin>>m;
  vector<vector<int>> v(m,vector<int>(26));
  for(i=0;i<m;i++){
    cin>>x;
    for(j=0;j<(int)x.length();j++) v.at(i).at(x.at(j)-'a')++;
  }
  for(j=0;j<26;j++){
    l=50;
    for(i=0;i<m;i++) l=min(l,v.at(i).at(j));
    for(k=0;k<l;k++) cout<<(char)('a'+j);
  }
  cout<<endl;
}