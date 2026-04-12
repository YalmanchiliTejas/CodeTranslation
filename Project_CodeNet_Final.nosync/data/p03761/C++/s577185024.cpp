#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int>data(26,0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for(int j = 0;j < s.size();j++){
    data[s[j]-'a']++;
  }
  for(int i = 1;i < n;i++){
    vector<int>pre(26,0);
    cin >> s;
    for(int j = 0;j < s.size();j++){
      pre[s[j]-'a']++;
    }
    for(int j = 0;j < 26;j++){
      if(data[j] > pre[j]) data[j] = pre[j];
    }
  }
  for(int i = 0;i < 26;i++){
    if(data[i] == 0) continue;
    for(int j = 0;j < data[i];j++){
      char t = 'a'+i;
      cout << t;
    }
  }
  cout << "" << endl;
}
