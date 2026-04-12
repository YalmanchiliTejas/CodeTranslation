#include <iostream>
#include <string>
using namespace std;

int main(){
  string s;
  while(true){
    cin >> s;
    if(s == "#")
      break;

    int rule[26] = {0, 0, 0, 0, 0,
                    0, 0, 1, 1, 1,
                    1, 1, 1, 1, 1,
                    1, 0, 0, 0, 0,
                    1, 0, 0, 0, 1, 0};
    
    int ans = 0;
    for(int i=0; i<s.size()-1; i++){
      if(rule[s[i] - 'a'] != rule[s[i+1] - 'a'])
        ans++;
    }
    cout << ans << endl;
  }
  
  return 0;
}