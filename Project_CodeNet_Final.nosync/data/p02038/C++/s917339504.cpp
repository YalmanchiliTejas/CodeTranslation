#include <iostream>


using namespace std;

enum animal{
  T,
  F
};

int
main(){
  int count;
  animal a=T;
  cin>>count;
  
  for(int i=0;i<count;i++){
    char input;
    animal next;
    cin>>input;

    next=input=='T'?T:F;

    if(a==T)
      a=next;
    else
      a=T;

  }

  cout<<((a==T)?'T':'F')<<endl;

  return 0;
}

