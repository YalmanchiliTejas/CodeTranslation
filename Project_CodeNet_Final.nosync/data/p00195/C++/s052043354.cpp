#include <iostream>
#include <algorithm>

using namespace std;

int main(void){

  int a,b;
  while( cin >> a >> b , a || b ){
    int ans = a + b;
    char ANS = 'A';
    for( int i = 1 ; i < 5 ; i++ ){
      cin >> a >> b;
      if( ans < a + b ){
	ans = a + b;
	ANS = 'A' + i;
      }
    }
    cout << ANS << " " << ans << endl;
  }
  return 0;
}