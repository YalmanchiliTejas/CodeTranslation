#include <iostream>
#include <map>
using namespace std;
typedef map<char, string> A;
typedef map<string, char> B;

int main() {
  int p, q, l;
  string s, t, u;
  bool f;
  A a;
  B b;
  const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
  const char *code1[]={
    "00000","00001","00010","00011","00100","00101","00110","00111",
    "01000","01001","01010","01011","01100","01101","01110","01111",
    "10000","10001","10010","10011","10100","10101","10110","10111",
    "11000","11001","11010","11011","11100","11101","11110","11111",
  };
  const char *code2[]={
    "100101","10011010","0101","0001","110","01001","10011011","010000",
    "0111","10011000","0110","00100","10011001","10011110","00101","111",
    "10011111","1000","00110","00111","10011100","10011101","000010","10010010",
    "10010011","10010000","101","010001","000011","10010001","000000","000001",
  };

  for (int i=0; i<32; i++) {
    a.insert(A::value_type(letters[i], string(code1[i])));
  }
  for (int i=0; i<32; i++) {
    b.insert(B::value_type(string(code2[i]), letters[i]));
  }

  while (getline(cin, s)) {
    t.clear();
    l = s.length();
    for (int i=0; i<l; i++) {
      t += a[s[i]];
    }
    f = false;
    p = 0;
    l = t.length();
    while (1) {
      q = 3;
      while (1) {
        u = t.substr(p, q);
        B::iterator it = b.find(u);
        if (it!=b.end()) {
          p += q;
          cout << it->second;
          break;
        }
        if (p+q>=l) {
          f = true;
          break;
        }
        q++;
      }
      if (f) break;
    }
    cout << endl;
  }
  return 0;
}