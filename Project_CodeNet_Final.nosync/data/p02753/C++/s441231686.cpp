#include <bits/stdc++.h>
#include <set>
#define rep(i,n) for (int i =0; i < (n); ++i)
using namespace std;
// 153b

int main() {
  char s[3];
  for(int i=0; i< 3 ;i++) cin >> s[i];
  
  if (s[0]==s[1]&&s[1]==s[2]){
    cout << "No" << endl;
    return 0;
}

cout << "Yes" << endl;
}