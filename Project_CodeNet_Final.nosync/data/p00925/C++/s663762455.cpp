#include <iostream>
using namespace std;

typedef int Val;
typedef pair<Val,int> Res;
#define val first
#define idx second

Res readExpr(string &s, int idx);
Res readTerm(string &s, int idx);
Res readFctr(string &s, int idx);

Res readExpr(string &s, int idx){
  Res r = readTerm(s, idx);
  while (s[r.idx]=='+'){
    Res r2 = readTerm(s, r.idx+1);
    r.val += r2.val;
    r.idx = r2.idx;
  }
  return r;
}
Res readTerm(string &s, int idx){
  Res r = readFctr(s, idx);
  while (s[r.idx]=='*'){
    Res r2 = readFctr(s, r.idx+1);
    r.val *= r2.val;
    r.idx = r2.idx;
  }
  return r;
}
Res readFctr(string &s, int idx){
  return Res(s[idx]-'0',idx+1);
}
Val LtoR(string &s){
  Val v;
  v = s[0]-'0';
  for (int i=1; i<s.size(); i+=2){
    if (s[i]=='+') v += s[i+1]-'0';
    else v *= s[i+1]-'0';
  }
  return v;
}

int main(void){
  string ex;
  int r,mul,ltr;
  string buf="IMLU";
  
  cin >> ex >> r;
  mul = readExpr(ex,0).val;
  ltr = LtoR(ex);
  cout << buf[(mul==r)+(ltr==r)*2] << endl;
  return 0;
}

