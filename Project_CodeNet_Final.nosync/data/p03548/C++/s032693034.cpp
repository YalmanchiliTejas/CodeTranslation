#include <bits/stdc++.h>
using namespace std;

int main(){
  int X,Y,Z;cin>>X>>Y>>Z;
  int count=0;
  int left=Z;
  while(true){
    if(left+Y+Z<=X){
      count++;
      left+=Y+Z;
    }
    else break;
  }
  cout<<count<<endl;
}

