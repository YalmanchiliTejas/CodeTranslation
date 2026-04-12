#include <set>
#include <string>
#include <iostream>

using namespace std;

int const none_s = 0;
int const left_s = 1;
int const right_s = 2;

int main()
{
  set<char> const left = {
    'q', 'w', 'e', 'r', 't',
    'a', 's', 'd', 'f', 'g',
    'z', 'x', 'c', 'v', 'b'
  };

  set<char> const right = {
    'y', 'u', 'i', 'o', 'p',
    'h', 'j', 'k', 'l',
    'n', 'm'
  };

  string s;
  while( cin >> s ) {
    if ( s == "#" ) {
      break;
    }

    int status = none_s;
    int times = 0;
    for( const char c : s ) {
      if ( left.find( c ) != left.end() ) {
        if ( status == right_s ) { ++times; }
        status = left_s;

      } else if ( right.find( c ) != right.end() ) {
        if ( status == left_s ) { ++times; }
        status = right_s;
      }
    }
    cout << times << endl;
  }
}