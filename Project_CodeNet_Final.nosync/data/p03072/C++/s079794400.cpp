#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int main( void ){
  
  	int a, a1;
	int sum = 1;
  
 	cin >> a;
 	for( int i = 0; i < a; i++ ){
  		int tmp;
      cin >> tmp;
      if( i == 0 ){
        a1 = tmp;
        continue;
       }
      if( a1 <= tmp ){
        sum++;
        a1 = tmp;
      }
    }
      
 	cout << sum << endl;
 	return 0;
}