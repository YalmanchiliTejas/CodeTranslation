#include <iostream>
using namespace std;
int main(void){
  int a;
  cin>>a;
  int b=a*800;
  int p=(a/15)*200;
  
  if(a<15){
      cout<<b<<endl;
  }
  
  else{
      cout<<b-p<<endl;
  }
}