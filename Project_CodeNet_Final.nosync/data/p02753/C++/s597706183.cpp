#include <iostream>
using namespace std;
int main(){
  char a[3];
  for(int i=0;i<3;i++){
    cin>>a[i];
  }
  if(a[0]==a[1]&&a[1]==a[2]){
    cout<<"No"<<endl;
  }
  else{
    cout<<"Yes"<<endl;
  }
}