#include<iostream>
using namespace std;
int main(){
  int a,b;
  while(true){
  int max = 0;
  int max_shop = 0;
    cin>>a>>b;
    if(!a&&!b)break;
  for(int i=0;i<5;i++){
    if(i)cin>>a>>b;
    if(a+b>max){
      max = a+b;
      max_shop = i;
    }
  }
  cout<<char(max_shop+65)<<" "<<max<<endl;
  }
  return 0;
}