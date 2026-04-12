#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define REP(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
using namespace std;

int main(){
  string s;
  cin >> s;
  if(s[0] == s[1] && s[1] == s[2]) cout << "No" << endl;
  else cout << "Yes" << endl;
}