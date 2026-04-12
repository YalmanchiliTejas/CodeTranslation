#include <iostream>
#include <stdbool.h>
using namespace std;

int main(){
  string s;
  bool isA = false, isB = false;
	cin>>s;
  for(int i=0; i<3; i++){
	if(s[i] == 'A') isA = true;
    else isB = true;
  }
  if(isA && isB) cout<<"Yes";
  else cout<<"No";
  return 0;
}