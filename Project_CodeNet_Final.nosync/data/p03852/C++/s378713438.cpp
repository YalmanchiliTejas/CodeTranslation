#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cassert>
#include <functional>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;


int main(){
  vector<char> list = {'a', 'i', 'u', 'e', 'o'};
  char c; cin >> c;
  if(find(list.begin(), list.end(), c) == list.end()) cout << "consonant" << endl;
  else cout << "vowel" << endl;
}
