#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<string.h>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
  int a=0, b=0;
  long long k;
  int ans = 0;
  string s;

  cin >> s;

  for(int i = 0; i < 3; i++){
    if(s[i]=='A')a++;
    else b++;
  }
  if(a == 3 || b == 3)cout << "No" << endl;
  else
  {
    cout << "Yes" << endl;
  }
}
