#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
 
int main() {
int h,w;
cin >> h >> w;
vector<vector<char>> a(h,vector<char>(w));
rep(i,h)rep(j,w) cin >> a.at(i).at(j);
int hcnt = 0,wcnt = 0;
vector<int> s;
vector<int> t;
rep(i,h){
  bool flag = true;
  rep(j,w){
    if(a.at(i).at(j) == '#') flag = false;
  }
  if(flag) hcnt++;
  else s.push_back(i);
}
rep(j,w){
  bool flag = true;
  rep(i,h){
    if(a.at(i).at(j) == '#') flag = false;
  }
  if(flag) wcnt++;
  else t.push_back(j);
}
for(int i: s)for(int j: t){
  if(j < t.back())cout << a.at(i).at(j);
  else cout << a.at(i).at(j) << endl;
}
}