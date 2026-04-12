#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <chrono>
#include <numeric>

using namespace std;


int main(){
  string s;
  cin >> s;
  for (int i=0;i<s.length()-1;i++) {
    if (s[i] == 'A' && s[i+1] == 'C') {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
