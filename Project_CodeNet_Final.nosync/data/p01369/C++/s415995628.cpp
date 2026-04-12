#include <iostream>
using namespace std;

int main() {
  char right[11] = {'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm'};
  char left[15] = {'q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', \
'v', 'b'};
  string str;
  bool r;
  int count;

  while(1) {
    cin >> str;
    if(str[0] == '#') break;

    r = false;
    for(int i = 0; i < 11; i++) {
      if(str[0] == right[i])
        r = true;
    }

    count = 0;
    for(int i = 1; i < str.size(); i++) {
      //前が右手のキー                                                               
      if(r == true) {
	for(int j = 0; j < 15; j++) {
          if(str[i] == left[j]) {
            r = false;
            count++;
            break;
          }
        }
      }
      //前が左手のキー                                                               
      else {
	for(int j = 0; j < 11; j++) {
          if(str[i] == right[j]) {
            r = true;
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
