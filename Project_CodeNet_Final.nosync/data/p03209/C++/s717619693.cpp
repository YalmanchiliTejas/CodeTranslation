#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
long rec(int lay, long res, long* l, long* p){
  if(lay==0){
    return res;
  }

  if(res == 1){
    return 0;
  } else if (res <= l[lay-1]+1){
    return rec(lay-1,res-1,l,p);
  } else if (res == l[lay-1]+2){
    return p[lay-1] + 1;
  } else if (res >= l[lay]-1){
    return p[lay];
  } else {
    return p[lay-1] + 1 + rec(lay-1,res-(l[lay-1]+2),l,p);
  }
}
int main() {
  long n,x;
  stringstream ss;
  cin >> n >> x;
  string b = "P";
  long* l = new long[51];
  l[0] = 1;
  for(int i=1;i<51;i++) l[i] = 2 * l[i-1] + 3;
  long* p = new long[51];
  p[0] = 1;
  for(int i=1;i<51;i++) p[i] = 2 * p[i-1] + 1;
  cout << rec(n,x,l,p)<< endl;
  return 0;
}
