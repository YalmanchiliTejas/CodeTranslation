#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
  int n;
  cin >> n;
  string s[n];
  for(int i = 0; i < n; i++) cin >> s[i];
  int a[n][26], b[26];
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 26; j++){
      a[i][j] = 0;
    }
  }
  for(int i = 0; i < 26; i++) b[i] = 0;

  int temp;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < s[i].length(); j++){
      temp = s[i][j] - 'a';
      a[i][temp]++;
    }
  }
  for(int i = 0; i < 26; i++){
    temp = 100;
    for(int j = 0; j < n; j++){
      temp = min(temp, a[j][i]);
    }
    b[i] = temp;
  }

  string ans = "";
  for(int i = 0; i < 26; i++){
    temp = b[i];
    string str(temp, 'a' + i);
    ans += str;
  }
  
  cout << ans << endl;
  return 0;
}
