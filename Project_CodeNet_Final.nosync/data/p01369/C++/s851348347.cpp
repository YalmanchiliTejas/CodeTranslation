#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

enum State{
  NONE,
  LEFT,
  RIGHT
};

int main (){
  const string right = "yhnujmikolp";
  while( 1 ){
    string s;
    cin >> s;
    if( s == "#" ){ return EXIT_SUCCESS; }
    int counter = 0;
    int len = s.length();
    State prev = NONE;
    State temp;
    for( int i = 0; i < len; i++ ) {
      if( right.find( s[ i ] ) == -1 ) {
        temp = LEFT;
      }else{
        temp = RIGHT;
      }
      if( temp != prev && prev != NONE ){
        counter++;
      }
      prev = temp;
    }
    cout << counter << endl;
  }
}