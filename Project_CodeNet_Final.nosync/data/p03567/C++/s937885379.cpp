#include <bits/stdc++.h>
using namespace std;
int main(){
  string str;
  cin >> str;
  string result = "No";
  for (int i = 0; i < str.length() - 1; ++i) 
  {
    if (str[i] == 'A' && str[i+1] == 'C') result = "Yes";
  }
  cout << result << endl;
  return 0;
}