#include<iostream>
using namespace std;

int main() {
  int n,k;
  string s;
  cin >> n >> s >> k;
  // 逐次出力.
  for(char c:s){
    if(c != s[k-1]) cout << '*';
    else cout << c;
  }
  return 0;
}