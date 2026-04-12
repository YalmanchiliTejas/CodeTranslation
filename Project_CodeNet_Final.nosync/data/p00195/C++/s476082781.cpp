//59
#include<iostream>

using namespace std;

int main(){
  for(;;){
    int ma=0;
    char shop;
    for(int i=0;i<5;i++){
      int s,ss;
      cin>>s>>ss;
      if(s==0&&ss==0)return 0;
      if(s+ss>ma){
	ma=s+ss;
	shop=i+'A';
      }
    }
    cout<<shop<<' '<<ma<<endl;
  }
  return 0;
}