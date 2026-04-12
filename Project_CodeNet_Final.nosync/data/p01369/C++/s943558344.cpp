#include <iostream>
#include <string>
using namespace std;
string s;
const string leftk = "qwertasdfgzxcvb";

void solve() {
  // l .. 0 , r .. 1
  int res = 0;
  int mode = (leftk.find(s[0]) != -1) ? 0 : 1 ;
  for (int i = 1; i < s.size(); i += 1) {
    if ((mode == 0 && leftk.find(s[i]) == -1) ||
        (mode == 1 && leftk.find(s[i]) != -1) ) {
      mode = !mode;
      res++;
    }
  }
  cout<<res<<endl;
}

int main (int argc, char const* argv[]) {
  while (cin>>s) {
    if (s != "#") solve();
  }
  return 0;
}