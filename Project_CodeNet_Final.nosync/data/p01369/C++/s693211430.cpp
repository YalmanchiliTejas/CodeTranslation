#include <iostream>
#include <string>
using namespace std;

int main(){
  string type;
  string qwer = "qwerttasdfgzxcvb";
  string yuio = "yuiophjklnm";
  
  while ( 1 ){
    cin >> type;
    if ( type == "#" ) break;
    int LR = 0;
    int count = 0;  //sayuukirikawari
    for ( int i = 0; i != type.size(); i++ ){
      if ( LR == 0 ){
	for ( int j = 0; j != qwer.size(); j++ ){
	  if ( type[i] == qwer[j] ){
	    LR++;
	    count++;
	    if ( i == 0 ) count--;
	    break;
	  }
	}
      }else{
	for ( int j = 0; j != yuio.size(); j++ ){
	  if ( type[i] == yuio[j] ){
	    LR--;
	    count++;
	    break;
	  }
	}
      }
    }
    cout << count << endl;
  }
  return 0;
}