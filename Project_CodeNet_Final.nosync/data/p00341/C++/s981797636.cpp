#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main(){
  vector<int> e(12);
  vector<int> length;
  cin>>e[0];
  length.push_back(e[0]);
  for(int i=1;i<12;i++){
    cin>>e[i];
    auto it=find(length.begin(),length.end(),e[i]);
    if(it==length.end())length.push_back(e[i]);
  }
  int size=length.size();
  if(size>=4){
    cout<<"no"<<endl;
    exit(0);
  }
  int i=0;
  bool ans=true;
  while(i<size){
    if(count(e.begin(),e.end(),length[i])%4!=0){
      ans=false;
    }
    i+=1;
  }
  if(ans==true)cout<<"yes"<<endl;
  else cout<<"no"<<endl;
}