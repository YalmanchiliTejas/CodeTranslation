#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(26,50);
  rep(x,n) {
    string s;
    cin >> s;
    vector<int> b(26);
    for(int i=0; s[i]!='\0'; i++) {
      b[s[i]-'a']++;
    }
    rep(i,26) {
      a[i]=min(a[i],b[i]);
    }
  }
  rep(x,26) {
    rep(i,a[x]) cout << (char)('a'+x);
  }
  cout << endl;
}
