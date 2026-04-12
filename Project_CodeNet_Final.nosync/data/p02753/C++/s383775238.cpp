#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long

using namespace std;

int main(){

  string S;
  cin >> S;

  if(S[0] == 'A' && S[1] == 'A' && S[2] == 'A' ) {
    cout << "No" << endl;
  } else if (S[0] == 'B' && S[1] == 'B' && S[2] == 'B' ){
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}