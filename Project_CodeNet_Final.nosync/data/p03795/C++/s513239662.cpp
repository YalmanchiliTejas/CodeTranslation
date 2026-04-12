#include<iostream>
using namespace std;

int main(){
  int n;
  while(cin>>n){
    int a=n/15,b=n%15;
    cout<<a*11800+b*800<<endl;
  }
  return 0;
}