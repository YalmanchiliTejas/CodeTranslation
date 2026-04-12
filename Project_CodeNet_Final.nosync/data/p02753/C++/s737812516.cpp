#include <iostream>
#include <string>
using namespace std;
int main(){
  char ser[3];
  cin >> ser;
  int i;
  int A=0;
  int B=0;
  for (i=0;i<=2;i++){
    if (ser[i]=='B'){
      B+=1;}
    if (ser[i]=='A'){
    	A+=1;
	}}
  if (A!=0 && B !=0){
    cout << "Yes";}
  else cout << "No";}