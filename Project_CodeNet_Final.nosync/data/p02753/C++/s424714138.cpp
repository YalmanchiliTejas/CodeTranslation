#include<iostream>
#include<string>
using namespace std;

int main(){
  string str;
  cin>> str;
  bool A  = false;
  bool B = false;
  for(int i = 0; i<str.length();i++){
  	if(str[i] == 'A'){
      A = true;
    }
    if(str[i] == 'B'){
      B = true;
    }
  }
  if(A and B){
    cout<<"Yes"<<'\n';
  }else{
  	cout<<"No"<<'\n';
  }
  return 0;
}