#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[]) {
  char c;
  cin >> c;
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
    cout << "vowel" << endl;
  }else{
    cout << "consonant" << endl;
  }
  return 0;
}
