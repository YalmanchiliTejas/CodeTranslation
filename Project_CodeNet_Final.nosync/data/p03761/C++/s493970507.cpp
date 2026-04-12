#include<bits/stdc++.h>

using namespace std;

#define INF 100

int main(){
  int n;
  cin >> n;
  
  vector<string> s(n);
  for(int i = 0; i < n; i++) cin >> s[i];
  
  int ch[n][26];
  for(int i = 0; i < n; i++) for(int j = 0; j < 26; j++) ch[i][j] = 0;
  
  for(int i = 0; i < n; i++) for(char c : s[i]) ch[i][c - 'a']++;
  
  for(int j = 0; j < 26; j++){
    int min_ch = INF;
    for(int i = 0; i < n; i++) min_ch = min(ch[i][j], min_ch);
    
    for(int i = 0; i < min_ch; i++) cout << (char)('a' + j);
  }
  cout << endl;
  
  return 0;
}