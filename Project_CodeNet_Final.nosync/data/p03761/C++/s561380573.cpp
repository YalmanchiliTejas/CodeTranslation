#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int x[27] = {};
  string str;
  cin >> str;
  for(int i = 0; i < str.size(); ++i){
    x[str[i]-'a']++;
  }
  for(int i = 1; i < n; ++i){
    string str2;
    cin >> str2;
    int x2[27] = {};
    for(int j = 0; j < str2.size(); ++j){
      x2[str2[j]-'a']++;
    }
    for(int j = 0; j < 27; ++j){
      x[j] = min(x[j], x2[j]);
    }
  }
  for(int i = 0; i < 27; ++i){
    for(int j = 0; j < x[i]; ++j){
      cout << (char)('a'+i);
    }
  }
  cout << endl;
  return 0;
}
