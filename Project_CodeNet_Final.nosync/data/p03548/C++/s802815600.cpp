#include<iostream>
using namespace std;

int main(){

  int x, y, z;

  cin>>x>>y>>z;

  for(int i=0;;i++){
    if(z+i*(y+z)>x){
      cout<<i-1<<endl;
      return 0;
    }
  }

  return 0;
}
