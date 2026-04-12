#include <iostream>
using namespace std;
int main(void){
    int a,b,c;
    cin>>a>>b>>c;
    int d=a*100;
    int e=b*10;
    int A=d+e+c;
    
  if(A%4==0){
      cout<<"YES"<<endl;
  }
  
  else{
      cout<<"NO"<<endl;
  }
}
