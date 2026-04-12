#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
  string s;

  cin >> s;
  for(int i = 0; i < s.length()-1; i++){
    if(s[i] == 'A'){
      if(s[i+1] == 'C'){
        cout << "Yes\n";
        return 0;
      }
    }
  }

  cout << "No\n";

   return 0;
}