#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n,k;
  string s;
  cin >>n >>s >>k;
  rep(i,n){
    if(s[i]!=s[k-1]) s[i] = '*';
  }
  cout << s << endl;
  return 0;
}