#include<cstdio>
#include<iostream>

using namespace std;

int main(){
  int i,j,k;
  string str="yuiophjklnm";
  bool r[1000];
  fill(r,r+1000,0);
  for(i=0;i<str.size();i++)
    r[str[i]]=1;
  

  while(1){
    cin>>str;
    if(str=="#")break;
    int cur=r[str[0]],re=0;
    for(i=1;i<str.size();i++){
      re+=(cur!=r[str[i]]);
      cur=r[str[i]];
    }
    cout<<re<<endl;
  }
  return 0;
}