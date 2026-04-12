#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int n, cnt[50][26] = {};
  string s, ans = "";
  
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> s;
    for(int j = 0;j < s.size();j++) cnt[i][s[j] - 'a']++;
  }
  
  for(int i = 0;i < 26;i++){
    int x = 50;
    for(int j = 0;j < n;j++) x = min(x, cnt[j][i]);
    for(int j = 0;j < x;j++) ans += (char)(i + 'a');
  }
  
  cout << ans << endl;
  
  return 0;
}