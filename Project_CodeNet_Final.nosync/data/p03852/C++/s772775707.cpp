#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string vector_finder(vector<char> vec, char element) {
  auto itr = find(vec.begin(), vec.end(), element);
  if (itr != vec.end()) {
    return "vowel";
  } else {
    return "consonant";
  }
}

int main() {
  vector<char> vec = {'a','e','i','o','u'};
  char c;

  cin >> c;

  cout << vector_finder(vec, c) << endl;
}