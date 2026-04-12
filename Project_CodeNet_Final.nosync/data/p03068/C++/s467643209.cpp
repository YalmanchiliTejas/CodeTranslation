#include <iostream>
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n;
  char s[n];
  cin >> s;
  cin >> k;
  k--;
  for(int i = 0; i < n; i++){
    if(s[i] != s[k]) s[i] = '*';
  }
  cout << s << endl;
  return 0;
}
