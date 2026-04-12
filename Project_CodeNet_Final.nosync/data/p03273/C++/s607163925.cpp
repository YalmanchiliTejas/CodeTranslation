#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int h, w;
  cin >> h >> w;
  set<int> rows;
  set<int> cols;
  vector<string> mp;
  rep(i, h){
    string str;
    cin >> str;
    mp.push_back(str);
  }
  rep(i, h){
    bool alldots = true;
    rep(j, w){
      if(mp[i][j] == '#') alldots = false;
    }
    if(alldots) rows.insert(i);
  }
  rep(j, w){
    bool alldots = true;
    rep(i, h){
      if(mp[i][j] == '#') alldots = false;
    }
    if(alldots) cols.insert(j);
  }
  rep(i, h){
    rep(j, w){
      if(rows.find(i) == rows.end() && cols.find(j) == cols.end()){
        cout << mp[i][j];
      }
    }
    if(rows.find(i) == rows.end()) cout << endl;
  }
  return 0;
}