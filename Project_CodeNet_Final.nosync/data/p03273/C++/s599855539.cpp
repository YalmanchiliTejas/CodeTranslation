#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)
char mp[100][100];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
  int h,w;
  cin>>h>>w;
  rep(i,h) {
    string tmp;
    cin>>tmp;
    rep(j,w) {
      mp[i][j] = tmp[j];
    }
  }
  vector<int> tate;
  rep(i,w) {
    rep(j,h) {
      if(mp[j][i]=='#') {
        tate.push_back(i);
        break;
      }
    }
  }
  vector<int> yoko;
  rep(i,h) {
    rep(j,w) {
      if(mp[i][j]=='#') {
        yoko.push_back(i);
        break;
      }
    }
  }
  for(auto &x : yoko) {
    for(auto &y : tate) {
      cout << mp[x][y];
    }
    cout << endl;
  }
  return 0;
}
