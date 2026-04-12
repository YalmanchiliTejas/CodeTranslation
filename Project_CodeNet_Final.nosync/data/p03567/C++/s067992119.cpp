#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#define MP make_pair
using ll = long long;
using namespace std;

int main()
{
  string s;
  cin >> s;
  bool b = false;
  for(int i=0; i < s.size()-1; i++){
    if(s[i]=='A' && s[i+1]=='C')
      b = true;
  }
  if(b)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
