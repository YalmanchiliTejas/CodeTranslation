#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k;
  string s;
  cin >> n >> s >> k;
  char c = s[k-1];
  for(int i = 0; i < n; i++){
    if(s[i] != c) cout << "*";
    else cout << c;
  }
  cout << endl;
  return 0;
}