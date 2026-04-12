#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define N 5005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int cnt1[26], cnt2[26];
int main() {
  cin>>n;
  memset(cnt1, 0, sizeof(cnt1));
  for (int i = 0; i < n; ++i) {
  	string s;
    cin>>s;
    memset(cnt2, 0, sizeof(cnt2));
    for (int j = 0; j < s.size(); ++j) {
    	cnt2[s[j]-'a']++;
    }
    if (i == 0) {
    	for (int j = 0; j < 26; ++j) {
        	cnt1[j] = cnt2[j];
        }
    } else {
    	for (int j = 0; j < 26; ++j) {
        	cnt1[j] = min(cnt1[j], cnt2[j]);
        }
    }
  }
  string ans="";
  for (int i = 0; i < 26; ++i) {
  	for (int j = 1; j <= cnt1[i]; ++j) {
    	ans.push_back('a' + i);
    }
  }
  sort(ans.begin(), ans.end());
  cout<<ans<<endl;
	return 0;
}