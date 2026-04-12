#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  int k;
  cin>>k;
  
  int m=s.at(k-1);
  
  for(int i=0;i<n;i++){
    if(s.at(i)!=m)
      s.at(i)='*';
  }
  cout<<s;
}