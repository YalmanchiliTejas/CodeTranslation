#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  string s;
  vector<char> vs, ans;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s;
    if(i == 0){
      for(int j = 0; j < s.size(); j++){
        vs.push_back(s[j]);
        ans.push_back(s[j]);
      }
    }
    else{
      ans.clear();
      for(int j = 0; j < s.size(); j++){
        for(int k = 0; k < vs.size(); k++){
          if(s[j] == vs[k]){
            // cout << "find " << s[j] << endl;
            ans.push_back(s[j]);
            vs.erase(vs.begin() + k);
            break;
          }
        }
      }
      vs.clear();
      vs.resize(ans.size());  //忘れないこと
      copy(ans.begin(), ans.end(), vs.begin());
    }
  }
  sort(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
