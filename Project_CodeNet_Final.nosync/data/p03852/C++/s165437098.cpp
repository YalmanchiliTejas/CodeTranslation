#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<queue>
#include<utility>
#include<cmath>
#include<sstream>
#include<istream>
#include<numeric>
#include<stdlib.h>

using namespace std;

int main()
{
  char c;

  cin >> c;

  if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
    cout << "vowel" << endl;
  }
  else{
    cout << "consonant" << endl;
  }

  return 0;
}
