#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin >> s;
  if(s.at(0)==s.at(1)){
    if(s.at(1)==s.at(2)){
      cout << "No" << "\n";
    }
    else{
      cout << "Yes" << "\n";
    }
  }else{
    cout << "Yes" << "\n";
  }
}