#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(void){
  char s[3];
  rep(i,3) cin >> s[i];
  bool a = 1;
  if(s[0] == s[1] && s[1] == s[2]) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}
