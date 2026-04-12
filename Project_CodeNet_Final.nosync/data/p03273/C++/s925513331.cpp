#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;
  
  //白列を除いてvを作成
  vector<string> v;
  for(int i=0; i<a; i++) {
    string s;
    cin >> s;
    for(int j=0; j<b; j++) {
      if(s[j] == '#') {
        v.push_back(s);
        break;
      }
    }
  }
  
  //vの縦横を入れ替えたwを作成
  int c = v.size();
  vector<string> w(b);
  for(int i=0; i<c; i++) {
    string s;
    s = v[i];
    for(int j=0; j<b; j++) {
      w[j] += s[j];
    }
  }
  
  //白列をwから削除
  for(int i=0; i<w.size(); i++) {
    string s;
    s = w[i];
    for(int j=0; j<c; j++) {
      if(s[j] == '#') break;
      if(j == c-1 && s[j] == '.') {
        w.erase(w.begin()+i);
        i--;
      }
    }
  }

  //wの縦横を入れ替えたxを作成
  int d = w.size();
  vector<string> x(c);
  for(int i=0; i<d; i++) {
    for(int j=0; j<c; j++) {
      string s;
      s = w[i];
      x[j] += s[j];
    }
  }
  
  //出力
  for(int i=0; i<c; i++) {
    cout << x[i] << endl;
  }
  return 0;
}