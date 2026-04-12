#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  int n;
  string s;
  int cnt1[26];

  for(int i = 0; i < 26; i++) cnt1[i] = 9999999;
  
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s;
    int cnt2[26] = {};
    for(int j = 0; j < s.size(); j++) cnt2[s[j] - 'a']++;
    for(int j = 0; j < 26; j++) cnt1[j] = min(cnt1[j], cnt2[j]);
  }
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < cnt1[i]; j++) cout << (char)('a' + i);
  }
  cout << endl;
}
