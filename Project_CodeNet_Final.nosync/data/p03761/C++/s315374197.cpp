#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<map<char,int>> d(n);
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    for(int j=0;j<s.size();j++)
      d.at(i)[s.at(j)]++;
  }
  map<char,int> m=d.at(0);
  for(auto x:m){
    char k=x.first;
    for(int i=0;i<n;i++)
      m[k]=min(m[k],d.at(i)[k]);
  }
  for(auto x:m)
    for(int i=0;i<x.second;i++)
      cout<<x.first;
  cout<<endl;
}