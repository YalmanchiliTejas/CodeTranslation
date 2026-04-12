#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;

int main() {
  int n, k;
  string s;

  cin >> n >> s >> k;


  k--;

  for(int i = 0; i < n; i++){
    if(s[k] == s[i]) {
      cout<<s[i];
    }else cout<<"*";
  }

  return 0;
}