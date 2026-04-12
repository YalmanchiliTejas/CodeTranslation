#include<iostream>
using namespace std;

int main(){
  char boin[5]={'a','i','u','e','o'};
  char c; cin>>c;
  for(int i=0;i<5;i++){
    if(c==boin[i]){
      cout<<"vowel"<<endl;
      return 0;
    }
  }
  
  cout<<"consonant"<<endl;
  return 0;
}