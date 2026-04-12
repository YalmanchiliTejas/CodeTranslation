//   _/                _/                 _/_/_/   _/
//_/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
// _/     _/    _/   _/     _/    _/  _/_/_/     _/
//_/     _/    _/   _/     _/    _/  _/    _/   _/
// _/_/   _/_/       _/_/   _/_/      _/_/     _/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const double pi=acos(-1);
const int inf=1e9;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  int h,w;
  char a[105][105]={};
  bool H[105]={},W[105]={};
  cin >> h >> w;
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      cin >> a[i][j];
      if(a[i][j]=='#') {
        H[i]=true,W[j]=true;
      }
    }
  }
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      if(H[i]&&W[j]) {
        cout << a[i][j];
      }
    }
    if(H[i]) {
      cout << endl;
    }
  }
}