#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<numeric>
#include<queue>
#include<string>
#include<sstream>

using namespace std;


int main(void) {

  string left = "qwertasdfgzxcvb";

  string s;
  while(cin >> s){
    if( s[0] == '#' ) break;
    vector<bool> b(s.size(), false);
    for(int i=0; i<s.size(); i++){
      for(int j=0; j<left.size(); j++){
        if( s[i] == left[j] ){
          b[i] = true;
          break;
        }
      }
    }
    int cnt = 0;
    bool f = b[0];
    for(int i=0; i<b.size(); i++){
      if( f != b[i] ){
        f = !f;
        cnt++;
      }
    }
    cout << cnt << endl;
  }

  return 0;
}










//