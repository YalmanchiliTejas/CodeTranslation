#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>

#define M 1000000007

using namespace std;

int found[26];

int main(){
  string s;
  cin >> s;

  bool isA = false;
  bool did = false;
  for(int i = 0;i < s.size();i++){
    if(s[i] == 'A'){
      isA = true;
    }else if(isA && s[i] == 'C'){
      did = true;
    }else{
      isA = false;
    }
  }

  cout << (did ? "Yes": "No") << endl;

  return 0;
}
