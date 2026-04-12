#include <bits/stdc++.h>
using namespace std;

#define right true
#define left false

int main(){
  map<char, bool> a;
  a['q'] = right;
  a['w'] = right;
  a['e'] = right;
  a['r'] = right;
  a['t'] = right;
  a['a'] = right;
  a['s'] = right;
  a['d'] = right;
  a['f'] = right;
  a['g'] = right;
  a['z'] = right;
  a['x'] = right;
  a['c'] = right;
  a['v'] = right;
  a['b'] = right;
  a['y'] = left;
  a['u'] = left;
  a['i'] = left;
  a['o'] = left;
  a['p'] = left;
  a['h'] = left;
  a['j'] = left;
  a['k'] = left;
  a['l'] = left;
  a['n'] = left;
  a['m'] = left;
  string s;
  while(cin >> s, s != "#"){
    int count = 0;
    bool flag = a[s[0]];
    for(unsigned int i = 1; i < s.size(); ++i){
      if(flag != a[s[i]]){
        flag = !flag;
        count++;
      }
    }
    cout << count << endl;
  }
  return 0;
}
