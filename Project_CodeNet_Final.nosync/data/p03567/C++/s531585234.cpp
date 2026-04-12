#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  
  auto pos = S.find("AC");
  if(pos != string::npos)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}