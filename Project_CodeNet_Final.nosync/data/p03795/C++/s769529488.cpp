#include <iostream>
using namespace std;
int main(){
  int n,paid,num,receive;
  cin>>n;
  paid=n*800;
  num=n/15;
  receive=num*200;
  cout<<paid-receive;
  return 0;
}