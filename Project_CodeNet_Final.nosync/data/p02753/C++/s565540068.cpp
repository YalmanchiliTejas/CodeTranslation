#include <cmath>
#include <iostream>
#include <functional>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <list>
#include <numeric>
using namespace std;

int main(){    
  long long N;
  string S;
  cin >> S;

  if(S[0]=='A' && S[1]=='A' && S[2]=='A'){
   cout << "No" << endl;
   return 0;
  }
  if(S[0]=='B' && S[1]=='B' && S[2]=='B'){
   cout << "No" << endl;
   return 0;
  }
  cout << "Yes" << endl;
}
