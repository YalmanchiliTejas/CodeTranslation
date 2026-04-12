#include <bits/stdc++.h>

#define stirng string
#define vvi vector<vector<int>>
#define vi vector<int>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

const int inf = 1e9 + 7;

int main() {
  int n;
  string s;
  int k;
  cin >> n >> s >> k;
  for(int i=0;i<n;i++){
    if(s[i] != s[k-1]){
      s[i] = '*';
    }
  }
  cout << s << endl;
  return 0;
}