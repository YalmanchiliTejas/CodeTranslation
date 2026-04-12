#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  vector<vector<int> > s_alpha(n, vector<int>(26, 0));
  vector<int> min_alpha(26, 999);
  for(int i = 0; i < n; i++){
    cin >> s[i];
    string cur = s[i];
    for(int j = 0; j < cur.length(); j++){
      char t = cur[j] - 'a';
      s_alpha[i][t]++;
    }

    for(int j = 0; j < 26; j++){
      // cout << min_alpha[j] << ", " << s_alpha[i][j] << endl;
      if(min_alpha[j] > s_alpha[i][j]){
        min_alpha[j] = s_alpha[i][j];
      }
    }
  }

  string ans = "";
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < min_alpha[i]; j++){
      char temp = 'a' + i;
      ans.push_back(temp);
    }
  }
  cout << ans << endl;
}
