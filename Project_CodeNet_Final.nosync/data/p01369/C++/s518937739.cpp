#include<iostream>
#include<string>
using namespace std;

enum version{
  fleft,
  fright,
};

version check(char c){
  switch(c){
  case 'q':
  case 'w':
  case 'e':
  case 'r':
  case 't':
  case 'a':
  case 's':
  case 'd':
  case 'f':
  case 'g':
  case 'z':
  case 'x':
  case 'c':
  case 'v':
  case 'b':
    return fleft;
  default:
    return fright;
  }
}

int main(){
  string input;
  while(cin>>input && input!="#"){
    version v=check(input[0]);
    int count=0;
    for(int i=1;i<(int)input.size();i++){
      version ver=check(input[i]);
      if(ver!=v){
	count++;
	v=ver;
      }
    }
    cout<<count<<endl;
  }
  return 0;
}