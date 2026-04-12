#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin >> s[i];

  for(int i=0;i<n;i++){
    sort(s[i].begin(),s[i].end());
  }

  vector<vector<int>> table(n,vector<int>(26));
  for(int i=0;i<n;i++){
    char prev = s[i][0];
    int cnt = 1;
    for(int j=1;j<s[i].size();j++){
      if(s[i][j] != prev){
        table[i][prev-'a'] = cnt;
        prev = s[i][j];
        cnt = 1;
      }else{
        cnt++;
      }
    }
    table[i][prev-'a'] = cnt;
  }

  string ans = "";
  for(int i=0;i<26;i++){
    int ap = 100;
    for(int j=0;j<n;j++){
      ap = min(ap,table[j][i]);
    }
    for(int k=0;k<ap;k++){
      ans += ('a'+i);
    }
  }

  cout << ans << endl;
}
