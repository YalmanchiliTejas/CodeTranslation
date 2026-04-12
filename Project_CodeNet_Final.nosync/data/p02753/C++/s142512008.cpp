#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int a=0;
  int b=0;
  for(int i=0;i<3;i++){
    if(s.at(i)=='A'){
      a++;
    }
    if(s.at(i)=='B'){
      b++;
    }
  }
  if(a==3||b==3){
    cout<<"No"<<endl;
  }
  else{
    cout<<"Yes"<<endl;
  }
}