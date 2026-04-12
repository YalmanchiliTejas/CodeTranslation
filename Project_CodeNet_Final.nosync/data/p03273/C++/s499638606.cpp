#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
string s[101];
int ii[101];
int jj[101];
int main(){
  int h,w;
  cin >> h >> w;
  rep(i,0,h - 1) cin >> s[i];
  rep(i,0,h - 1) rep(j,0,w - 1) if(s[i][j] == '#') ii[i] = jj[j] = 1;
  rep(i,0,h - 1) if(ii[i]){
    rep(j,0,w - 1) if(jj[j]){
      cout << s[i][j];
    }
    cout << endl;
  }
}
