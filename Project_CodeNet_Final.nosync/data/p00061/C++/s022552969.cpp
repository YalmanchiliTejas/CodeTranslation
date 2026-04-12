#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

  int score[100] = {0};
  vector<int> list;

  int input1,input2;
  char c;

  while(true) {

    cin >> input1 >> c >> input2;
    if ( input1 == 0 ) break;

    score[input1-1] = input2;

    if ( count( list.begin(), list.end(), input2 ) == 0 ) list.push_back(input2);

  }

  sort( list.begin(), list.end() );

  while( cin >> input1 ) {

    for ( int i = 1; i <= list.size(); i++ ) {

      if ( score[input1-1] == list[list.size()-i] ) {
	cout << i << endl;
	break;
      }

    }

  }

  return 0;

}