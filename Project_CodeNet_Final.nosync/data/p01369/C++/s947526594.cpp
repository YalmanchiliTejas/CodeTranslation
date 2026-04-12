#include<iostream>
#include<string>
#include<algorithm>
using namespace std; 

int main(){
  int x,y;
  string a,q;
  q="qwertasdfgzxcvb";
  while(cin>>a){
    int ans=0;
    if(a=="#"){
      break;
    }
    if(q.find(a[0])!=string::npos){
      x=0;
    }else{
      x=1;
    }
    for(int i=1;i<a.size();i++){
      if(q.find(a[i])!=string::npos){
	y=0;
      }else{
	y=1;
      }
      if(x!=y){
	ans++;
      }
      x=y;
    }
    cout<<ans<<endl;
  }
    return 0;
}