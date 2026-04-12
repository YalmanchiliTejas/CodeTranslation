#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> data;

main(){
  string str;
  data['a'] = 0;
  data['b'] = 0;
  data['c'] = 0;
  data['d'] = 0;
  data['e'] = 0;
  data['f'] = 0;
  data['g'] = 0;
  data['h'] = 1;
  data['i'] = 1;
  data['j'] = 1;
  data['k'] = 1;
  data['l'] = 1;
  data['m'] = 1;
  data['n'] = 1;
  data['o'] = 1;
  data['p'] = 1;
  data['q'] = 0;
  data['r'] = 0;
  data['s'] = 0;
  data['t'] = 0;
  data['u'] = 1;
  data['v'] = 0;
  data['w'] = 0;
  data['x'] = 0;
  data['y'] = 1;
  data['z'] = 0;

  while(cin >> str){
    if(str == "#") break;
    int p = data[str[0]];
    int ans = 0;
    for(int i=1;i<str.size();i++){
      if(p != data[str[i]]) ans++;
      p = data[str[i]];
    }
    cout << ans << endl;
  }
  return 0;
}