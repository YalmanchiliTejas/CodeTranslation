#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  int a,b,mx;

  while( cin >> a >> b, a+b ){
    char ans = 'A';
    mx =  a + b;
      for(int i = 1 ; i < 5 ; i++ ){
	cin >> a >> b;
	if(mx < a+b){
	  mx = a+b;
	  ans = char('A'+i); 
	}
      }
      cout << ans <<' '<<mx << endl;
  }
  return 0;
}