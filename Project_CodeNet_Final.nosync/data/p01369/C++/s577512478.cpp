#include <iostream>
#include <cstring>
using namespace std;

int main(){

  string key[20] = {"y","u","i","o","p","h","j","k","l","n","m"}; 

  string x;

  while(1){

    cin >> x;
    if(x == "#") break;  

    int flag = 1;; // 0 右　１左
    int c = 0;

    for(int j = 0 ; j < 11 ; j++){
      if( x[0] == key[j][0] )
	flag = 0;
    }


    for(int i = 0 ; i < x.size() ; i++){

      for(int j = 0 ; j < 11 ; j++){

	if( x[i] == key[j][0] ){

	  if(flag == 1){
	    c++;
	    flag = 0;
	    break;
	  }
	  else{
	    break;
	  }

	}
	if( j == 10 ) 
	  if(flag == 0){
	    c++;
	    flag = 1;
	  }
      }
    }

    cout << c << endl;

  }


  return 0;
}