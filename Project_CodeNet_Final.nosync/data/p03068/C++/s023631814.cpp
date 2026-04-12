#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  string s;
  char c;
  std::cin >> n;
  std::cin >> s;
  std::cin >> k;
  c=s[k-1];
  for (int i = 0; i < n; i++) {
      /* code */
      if(c!=s[i])s[i]='*';
  }
  std::cout << s << std::endl;
}