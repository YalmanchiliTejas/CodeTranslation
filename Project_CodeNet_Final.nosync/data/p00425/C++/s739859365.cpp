#include <iostream>
#include <string>
using namespace std;

int main(){
  int n,m,p;
  string s;
  while(cin>>n,n){
    m=1;
    int d[6]={1,6,2,5,3,4};
    while(n--){
      cin>>s;
      switch(s[0]){
      case 'N':
	p=d[0];d[0]=d[2];d[2]=d[1];d[1]=d[3];d[3]=p;m+=d[0];break;
      case 'E':
	p=d[0];d[0]=d[5];d[5]=d[1];d[1]=d[4];d[4]=p;m+=d[0];break;
      case 'W':
	p=d[0];d[0]=d[4];d[4]=d[1];d[1]=d[5];d[5]=p;m+=d[0];break;
      case 'S':
	p=d[0];d[0]=d[3];d[3]=d[1];d[1]=d[2];d[2]=p;m+=d[0];break;
      case 'R':
	p=d[2];d[2]=d[4];d[4]=d[3];d[3]=d[5];d[5]=p;m+=d[0];break;
      case 'L':
	p=d[2];d[2]=d[5];d[5]=d[3];d[3]=d[4];d[4]=p;m+=d[0];break;
      }
    }
    cout<<m<<endl;
  }
  return 0;
}