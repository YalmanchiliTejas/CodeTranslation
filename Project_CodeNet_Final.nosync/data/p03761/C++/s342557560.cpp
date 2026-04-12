#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  map<char,int> mp[n];
  for ( int i = 0; i < n; i++){
    cin >> s;
    for ( int j = 0; j < s.length(); j++){
      mp[i][s[j]]++;
    }
  }

  string ans = "";
  for ( map<char,int>::iterator it=mp[0].begin(); it!=mp[0].end(); it++){
    char key = it->first;
    int minV = 100;
    for (int i = 0; i < n; i++){
      minV = min( mp[i][key], minV);
    }
    for(int i = 0; i < minV; i++){
      ans+=key;
    }
  }

  cout << ans << endl;

  return 0;
}