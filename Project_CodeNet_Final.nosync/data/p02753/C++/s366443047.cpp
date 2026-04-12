#include <bits/stdc++.h>
// #include <vector.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main()
{
  string s;
  cin >> s;
  if(s.at(0) == s.at(1) && s.at(1) == s.at(2)){
    cout << "No" << endl;
  } else { 
    cout << "Yes" << endl;
  }
  //cout << s << endl;
  return 0;
}
