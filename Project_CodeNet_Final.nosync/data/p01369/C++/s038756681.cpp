#include <iostream>
#define REP(i, n) for(int i = 0; i < (n); i++)
using namespace std;

int main()
{
  string s;
  while(1){
    getline(cin, s);
    if(s[0] == '#'){
      break;
    }else{
      int state = -1, ans = 0;
      string left = "qwertasdfgzxcvb";
      string right = "yuiophjklnm";
      REP(i, s.size()){
        if(left.find(s[i], 0) != string::npos){
          if(state == 1)
            ans++;
          state = 0;
        }else{
          if(state == 0)
            ans++;
          state = 1;
        }
      }
      cout << ans << endl;
    }
  }
}