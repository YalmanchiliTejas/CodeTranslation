#include <algorithm>
#include <iostream>
using namespace std;

int main() {

  string l = "yuiophjklnm";
  while(1) {
      string s;
      cin >> s;

      if(s == "#") break;

      int ans = 0;
      bool r = false;
      for(int i = 0; i < s.size(); i++) {

        bool flag = false;
        for(int j = 0; j < l.size(); j++) {
          if(s[i] == l[j]) {
            flag = true;
            break;
          }
        }

        if(flag) {
          if(!r && i != 0) ans++;
          r = true;
        } else {
          if(r && i != 0) ans++;
          r = false;
        }
      }
      cout << ans << endl;
  }

	return 0;
}