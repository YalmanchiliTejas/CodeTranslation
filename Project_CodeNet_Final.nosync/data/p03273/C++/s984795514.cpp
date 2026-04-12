#include <bits/stdc++.h>
using namespace std;
int main(void){
  int h,w,i,j;
  cin >> h >> w;
  vector<bool> ki(h+5,true),kj(w+5,true);
  vector<string> g(h+5,"");
  for (i=0;i<h;i++) cin >> g.at(i);
  for (i=0;i<h;i++){
    for (j=0;j<w;j++) if (g.at(i).at(j)!='.') break;
    if (j==w) ki.at(i)=false;
  }
  for (j=0;j<w;j++){
    for (i=0;i<h;i++) if (g.at(i).at(j)!='.') break;
    if (i==h) kj.at(j)=false;
  }
  for (i=0;i<h;i++){
    for (j=0;j<w;j++) if (ki.at(i)&&kj.at(j)) cout << g.at(i).at(j);
    if (ki.at(i)) cout << endl;
  }
  return 0;
}