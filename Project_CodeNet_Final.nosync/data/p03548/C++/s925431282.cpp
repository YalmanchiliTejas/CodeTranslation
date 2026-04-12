#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int X,Y,Z,count;
  cin>>X>>Y>>Z;
  while(count*Y+(count+1)*Z<=X){
    count++;
  }
  cout<<count-1<<endl;
  return 0;
  }