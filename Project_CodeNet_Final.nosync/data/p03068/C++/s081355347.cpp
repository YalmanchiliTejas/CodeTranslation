#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void){
  int n;
  int k;
  cin >> n;
  vector<char> s(n);
  for(int i=0; i<n; ++i) cin >> s[i];
  cin >> k;
  char target = s[k-1];
  for(int i=0; i<n; ++i){
    if(s[i]==target) cout << target;
    else cout << "*";
  }
  cout << endl;
  return 0;
}