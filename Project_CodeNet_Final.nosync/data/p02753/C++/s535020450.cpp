#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  char c1;
  char c2;
  char c3;
  set<char> s;
  cin>>c1;
  cin>>c2;
  cin>>c3;
  s.insert(c1);
  s.insert(c2);
  s.insert(c3);
  if(s.size() > 1){
    cout<<"Yes"<<'\n';
  }else{
    cout<<"No"<<'\n';
  }  
}