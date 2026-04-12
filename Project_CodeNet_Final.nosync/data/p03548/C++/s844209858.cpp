#include<iostream>
using namespace std ;

int main()
{
  int X,Y,Z ;
  cin>>X>>Y>>Z ;
  
  int num ;
  for(num=1;;num++){
    if(X-num*Y-(num+1)*Z==0){
      cout<<num<<endl ;
      return 0 ;
    }else if(X-num*Y-(num+1)*Z<0) break ;
  }
  cout<<num-1<<endl ;
  return 0 ;
}