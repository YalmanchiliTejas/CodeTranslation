#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

string itob(int a) {
  string ret;
  for(int i=16; i>0; i/=2) {
    if (a>=i) {
      ret+='1';
      a-=i;
    } else
      ret+='0';
  }
  return ret;
}

int main() {
  string hoge = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
  map<char, string> m;
  REP(i,hoge.length()) {
    //  string hage;
    // hage = hoge[i];
    m.insert(make_pair(hoge[i],itob(i)));
  }
  hoge = " ',-.?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string hoge2[] = {"101","000000","000011","10010001","010001","000001","100101","10011010"
                 ,"0101","0001","110","01001","10011011","010000","0111","10011000"
                 ,"0110","00100","10011001","10011110","00101","111","10011111","1000"
                 ,"00110","00111","10011100","10011101","000010","10010010","10010011","10010000"};
  map<string,char> m2;
  REP(i,hoge.length())
    m2.insert(make_pair(hoge2[i],hoge[i]));
  string line;
  while(getline(cin,line)) {
    string a;
    REP(i,line.length())
      a += m[line[i]];
    string ans;
    for (int i=0; i<a.length(); i++) {
      string tmp;
      for (int j=i; j<a.length(); j++) {
        tmp += a[j];
        i = j;
        if (m2.count(tmp)) {
          ans += m2[tmp];
          break;
        }
      }
    }
    cout << ans << endl;
  }
}