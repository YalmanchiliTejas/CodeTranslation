#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  string s;
  cin >> n;
  int c[26];
  fill(c, c + 26, 1e9);
  for (int i = 0; i < n; i++) {
	cin >> s;
	int b[26];
	fill(b, b + 26, 0);
	for (int j = 0; j < s.size(); j++) {
	  b[s[j] - 'a']++;
	}
	for (int j = 0; j < 26; j++) {
	  c[j] = min(c[j], b[j]);
	}
  }
  string ans;
  for (int i = 0; i < 26; i++) {
	for (int j = 0; j < c[i]; j++) {
	  ans += i + 'a';
	}
  }
  sort(ans.begin(), ans.end());
  cout << ans << endl;

  return 0;
}

