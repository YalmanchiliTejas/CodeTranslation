#include <iostream>
#include <unordered_set>
#include <sstream>
using namespace std;
bool isRight(char);

int main() {
  string buff;
  while(cin >> buff, buff != "#") {
    stringstream word;
    word << buff;
    int count = 0;
    char c;
    word >> c;
    bool isLastRight = isRight(c);
    while(word >> c) {
      if(isLastRight != isRight(c)) ++count;
      isLastRight = isRight(c);
    }
    cout << count << endl;
  }
  return 0;
}

bool isRight(char c) {
  unordered_set<char> rights{'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm'};
  return (rights.find(c) != rights.end());
}