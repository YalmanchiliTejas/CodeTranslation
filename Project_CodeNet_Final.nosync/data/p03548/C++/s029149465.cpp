#include <iostream>
using namespace std;

int main(void){
  int x,y,z;
  cin>>x>>y>>z;
  int sum=z;
  int cnt=0;
  while(x>sum){
    sum=sum+y+z;
    if(x<sum) break;
    cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}