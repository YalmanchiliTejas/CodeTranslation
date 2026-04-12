#include<iostream>
using namespace std;
int main () {

  int N,T,E,x[100],num=-1,a;

  cin >>N>>T>>E;
  
  for(int i=0 ; i < N ; i++){
    cin >>x[i];
    a=(T+E)%x[i];
    if( a <= 2*E ){
      num=i+1;
    }
  }
  
  cout <<num<<endl;
  
  return 0;
  
}