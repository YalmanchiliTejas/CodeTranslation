#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

bool comp(const std::string& lh, const std::string& rh) {
     
    return lh.length() < rh.length();
}

int main(){
  int n;
  cin >> n;
  vector<int> ans(26, 100);
  rep(i, n){
    vector<int> vec(26, 0);
    string str;
    cin >> str;
    rep(j, str.length()) vec[str[j]-'a']++;
    rep(j, 26) ans[j] = min(ans[j], vec[j]);
  }
  string str = "";
  rep(i, 26){
    rep(j, ans[i]){
      str += 'a'+i;
    }
  }
  cout << str << endl;
  return 0;
}