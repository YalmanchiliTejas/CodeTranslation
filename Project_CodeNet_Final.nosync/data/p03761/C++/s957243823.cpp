#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<set>
#include<queue>
using namespace std;

typedef long long ll;
int app[55][26];
int ans[26];
int main() {
  int n; cin >> n;
  string s[55];
  string a = "";
  for ( int i = 0; i < 26; i++ ) ans[i] = 100;
  
  for ( int i = 0; i < n; i++ ) {
    cin >> s[i];
  }

  for ( int i = 0; i < n; i++ ) {
    for ( int j = 0; j < s[i].length(); j++ ) {
      app[i][s[i][j]-'a']++;
    }
  }

  for ( int i = 0; i < n; i++ ) {
    for ( int j = 0; j < 26; j++ ) {
      ans[j] = min(ans[j],app[i][j]);
    }
  }
  /*
  for ( int i = 0; i < 26; i++ ) {
    cout << ans[i] << " ";
  }
  cout << endl;
  */
  for ( int i = 0; i < 26; i++ ) {
    if ( ans[i] > 0 ) {
      for ( int j = 0; j < ans[i]; j++ ) {
	//cout << "======" << i+'a' << endl;
	a += i+'a';
      }
    }
  }

  cout << a << endl;
  return 0;
}
