#include<iostream>
#include<cstdio>
using namespace std;


bool LR(char c){

  if(('a'<=c && c<='g') || ('q'<= c && c <= 't') 
     || c=='v' || c=='w' || c=='x' || c=='z')
    return true;

  else
    return false;


}

int main(){

  char in;
  int sum;
  bool prev;

  while(1){

    scanf("%c",&in);
    if(in == '#'){ break; }
    prev = LR(in);


    sum = 0;

    
    while(scanf("%c",&in)){
      if(in == '\n'){
	break;
      }
      else{

	if(prev != LR(in) ){
	  sum ++;
	  prev = LR(in);
	}

      }

    }

    cout << sum << endl;



  }

  return 0;
}