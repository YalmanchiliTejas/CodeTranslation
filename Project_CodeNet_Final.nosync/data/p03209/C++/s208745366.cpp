#include <iostream>
using namespace std;

int main(){
  long long int N,X;
  cin >> N >> X;
  
  long long int burger, p;
  burger=1;
  p=1;
  
  for(int i=0;i<N;i++){
    burger=burger*2+3;
    p=p*2+1;
  }
  
  long long int a=0;
  while(X!=0){
    if(X==1){X=0;}
    else if(X<=(burger-3)/2+1){burger=(burger-3)/2;p=(p-1)/2;X-=1;}
    else if(X==(burger-3)/2+2){a+=1+(p-1)/2;X=0;}
    else if(X<=2+(burger-3)){a+=1+(p-1)/2;burger=(burger-3)/2;p=(p-1)/2;X=X-2-burger;}
    else{a+=p;X=0;}
  }
  if(burger==1 && N>=2){a++;}
  
  cout << a << endl;
  
  return 0;
}