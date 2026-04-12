#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<math.h>
#include<assert.h>
#include<string>
#include<cstdlib>
//#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long INF = 1LL << 40;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
// ----------------------------------------------------------------------------

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  sort(s.begin(),s.end());
  vector<int> ok(26,0);
  for(int i=0; i<s.size(); i++){
    ok[s[i] - 'a']++;
  }
  for(int i=1; i<n; i++){
    string t;
    cin >> t;
    sort(t.begin(),t.end());
    vector<int> temp(26,0);
    for(int j=0; j<t.size(); j++){
      temp[t[j] - 'a']++;
    }
    for(int j=0; j<26; j++){
      chmin(ok[j],temp[j]);
    }
  }
  for(int i=0; i<26; i++){
    for(int j=0; j<ok[i]; j++){
      cout << (char)('a'+i);
    }
  }
  cout << endl;
  return 0;
}
