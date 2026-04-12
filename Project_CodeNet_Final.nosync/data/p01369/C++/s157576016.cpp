#include <iostream>
#include <string.h>
using namespace std;
int main(){
  string left="zaqxswcdevfrbgt";
  string right="nhymjukilop";
  string input;
  while (1){
    int count=-1;
    int boo=0;
    cin>>input;
    for (int i=0;i<input.length();i++){
      for (int j=0;j<right.length();j++){
	if (input[i]==right[j]){
	  if (boo!=1)
	    count++;
	  boo=1;
	  break;
	}
      }
      for (int l=0;l<left.length();l++){
	if (input[i]==left[l]){
	  if (boo!=2)
	    count++;
	  boo=2;
	  break;
	}
      }
    }
    if (input=="#"){
      break;
    }
    cout<<count<<endl;
  }
  return 0;
} 