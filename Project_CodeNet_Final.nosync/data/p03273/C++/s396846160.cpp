/*   _/                _/                 _/_/_/   _/
  _/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
   _/     _/    _/   _/     _/    _/  _/_/_/     _/
  _/     _/    _/   _/     _/    _/  _/    _/   _/
   _/_/   _/_/       _/_/   _/_/      _/_/     _/ */
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const double pi=3.14159265358979323846;
const int inf=2e9;
const ll INF=1e18;
using P=pair<int,int>;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  int h,w,x[105]={},y[105]={},cnt,f;
  string s[105]={};
  cin >> h >> w;
  for(int i=0; i<h; i++) {
    cin >> s[i];
  }
  for(int i=0; i<h; i++) {
    cnt=0;
    for(int j=0; j<w; j++) {
      if(s[i][j]=='.') {
        cnt++;
      }
    }
    if(cnt==w) {
      x[i]=1;
    }
  }
  for(int i=0; i<w; i++) {
    cnt=0;
    for(int j=0; j<h; j++) {
      if(s[j][i]=='.') {
        cnt++;
      }
    }
    if(cnt==h) {
      y[i]=1;
    }
  }
  for(int i=0; i<h; i++) {
    f=0;
    for(int j=0; j<w; j++) {
      if(!x[i]&&!y[j]) {
        cout << s[i][j];
        f=1;
      }
    }
    if(f) {
      cout << "\n";
    }
  }
}