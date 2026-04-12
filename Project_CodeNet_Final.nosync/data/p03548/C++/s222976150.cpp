#include <iostream>
using namespace std;
int main(){
  int x,y,z;
  cin>>x>>y>>z;
  for(int i=0;i<100000;i++){
    if(x<(y*i+z*(i+1))){
      cout<<i-1<<endl;
      return 0;
    }
  }
}