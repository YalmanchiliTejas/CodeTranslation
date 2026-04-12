#include<bits/stdc++.h>

using namespace std;

int alphabet[26];

int main(){
  int N;  cin >> N;
  
  for(int i = 0; i < 26; i++){ alphabet[i] = 1e9;}
  
  
  vector<vector<int>> alphabetical(N, vector<int>(26,0));
  for(int i = 0; i < N; i++){
    string S; cin >> S; 
    for(int j = 0; j < (int) S.size(); j++){
      int c = S[j] - 'a';
      alphabetical[i][c]++;}
  }
  
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < N; j++){
      alphabet[i] = min(alphabet[i], alphabetical[j][i]);}}
  
  string ans = "";
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < alphabet[i]; j++){
      char d = i + 'a';
      ans += d;}}  sort( ans.begin(),ans.end());
  
  cout << ans << endl; return 0;}
  