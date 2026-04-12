#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;

int main()
{
  int n;
  cin >> n;

  map<char, int> mp[n];
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;

    for(int j = 0; j < s.size(); j++){
      mp[i][s[j]]++;
    }
  }

  string ans;
  for(int i = 0; i < 26; i++){
    int cnt = 1e9;
    for(int j = 0; j < n; j++){
      cnt = min(cnt, mp[j]['a'+i]); 
    }
    for(int j = 0; j < cnt; j++){
      ans += ('a'+i);
    }
  }

  cout << ans << endl;

  return 0;
}
