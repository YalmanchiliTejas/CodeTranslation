#include<iostream>
using namespace std;
int main(){
   int x,y,z,i=0;
   cin>>x>>y>>z;
  while(i<=(x-z)/(y+z)){i++;}
  cout<<i-1<<endl;
  return 0;
}
  