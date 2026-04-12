#include<bits/stdc++.h>
using namespace std;
int main(){
  bool a=false,b=false;
  char tmp;
  for(int i=0;i<3;i++){
    cin>>tmp;
    if(tmp=='A')a=true;
    else b=true;
  }
  if(a&&b)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}