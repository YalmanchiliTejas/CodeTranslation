#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
int main(){
  int n,k;
  string s;
  cin >> n >> s >> k;
  string temp = s.substr(k-1,1);
  char c = *temp.c_str();
  rep(i,n){
    if(c != s[i]){
      s[i]='*';
    }
  }
  cout << s <<endl;
  return 0;
}