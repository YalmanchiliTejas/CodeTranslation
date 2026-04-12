#include <iostream>
using namespace std;
int main(){
  int a,b=0,c,count=0;
  cin>>a;
  for(int i=0;i<a;i++){
    cin>>c;
    if(b<=c){
      count++;
      b=c;
    }
  }
  cout<<count<<endl;
}