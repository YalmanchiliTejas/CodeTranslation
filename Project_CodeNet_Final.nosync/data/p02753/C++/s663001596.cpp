#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
int main(){
  char s[3];
  rep(i,3){
    cin >> s[i];
  }
  if(s[0]==s[1]&&s[1]==s[2]){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" <<endl;
  return 0;
}