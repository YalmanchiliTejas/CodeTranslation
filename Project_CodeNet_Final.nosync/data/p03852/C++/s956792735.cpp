#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main( int argc, char** argv ){
	char c;
  
  cin >> c;
  
  if( c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ){
    cout << "vowel" << endl;
  }else{
    cout << "consonant" << endl;
  }
  
	return 0;
}
