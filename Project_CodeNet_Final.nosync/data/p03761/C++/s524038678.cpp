#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> vv(n, vector<int>(26, 0));
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    int len = s.length();
    for(int j=0;j<len;j++){
      vv[i][s[j]-'a']++;
    }
  }
  int flag=0;
  for(int i=0;i<26;i++){
    int mi=vv[0][i];
    for(int j=1;j<n;j++){
      mi = min(mi, vv[j][i]);
    }
    char x = i + 'a';
    for(int j=0;j<mi;j++){
      flag=1;
      cout << x;
    }
  }
  if (flag == 0){
    cout << "" << endl;
  }else{
    cout << endl;
  }
  return 0;
}