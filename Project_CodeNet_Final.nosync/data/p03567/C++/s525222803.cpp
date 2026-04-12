#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  int flag=0;
  for(int i=0;i<s.size()-1;i++)
    if(s.at(i)=='A' && s.at(i+1)=='C')flag++;
  if(flag==0)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}