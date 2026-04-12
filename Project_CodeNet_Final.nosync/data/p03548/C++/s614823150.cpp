#include<bits/stdc++.h>
using namespace std;
int main(){
  int X,Y,Z;
  cin>>X>>Y>>Z;
  int h=Y+Z;
  if(X%h<Z){
    cout<<X/h-1<<endl;
  }
  else{
    cout<<X/h<<endl;
  }
}
