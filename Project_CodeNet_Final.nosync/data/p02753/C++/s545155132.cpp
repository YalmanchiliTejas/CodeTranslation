#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int count=0;
  for(int i=0;i<3;i++){
    if(s[i]=='A'){
      count++;
    }else if(s[i]=='B'){
      count--;
    }
  }

  if(count==3 || count==-3){
    cout<<"No"<<endl;
  }else{
    cout<<"Yes"<<endl;
  }
}
