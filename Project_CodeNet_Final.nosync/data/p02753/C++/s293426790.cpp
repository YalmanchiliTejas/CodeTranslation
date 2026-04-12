#include<iostream>
using namespace std;
int main(){
  char c[4];
  for(int i=0; i<3; i++) {
    cin>>c[i];
  }
  c[3] = '\0';
  if(!strcmp(c,"AAA")||!strcmp(c,"BBB")) {
    cout<<"No";}
  else {
    cout<<"Yes";
  }
}
