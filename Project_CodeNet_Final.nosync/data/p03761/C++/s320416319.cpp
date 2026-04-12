#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string ans = "";
  cin >> n;
  vector<vector<int>>data(n,vector<int>(26,0));
  for(int i = 0;i < n;i++){
    string s;
    cin >> s;
    for(int j = 0;j < s.size();j++){
      int k;
      k = s.at(j)-'a';
      data[i][k]++;
    }
  }
  for(int i = 0;i < 26;i++){
    int min;
    min = data[0][i];
    if(n != 1){
      for(int j = 1;j < n;j++){
        if(data[j][i] <= min){
          min = data[j][i];
        }
      }
    }
    for(int j = 0;j < min;j++){
      ans += 'a'+i;
    }
  }
  cout << ans << endl;
}
