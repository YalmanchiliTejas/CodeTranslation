#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()

using namespace std;

int main(){
  char c; cin >> c;
  string v="aeiou";
  for (int i=0; i<5; i++) {
    if (v[i]==c) {
      cout << "vowel" << endl;
      return 0;
    }
  }
  cout << "consonant" << endl;
  return 0;
}