#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int main() {
  int t=0,y=0;
  map<int,int> m;
  vector<int> a(12);
  rep(i, 12) cin >> a[i];
  rep(i,12){
    m[a.at(i)]++;
  }
  for (auto &v: m) y++;
  if (y==3){
    for (auto &v: m) if (v.second!=4) t=1;
  }
  else if (y==2){
    for (auto &v: m) {
        if (v.second==4 || v.second==8) t++;
    }
    if (t==2) t=0;
    else t=1;
  }
else if (y==1){
    for (auto &v: m) if (v.second!=12) t=1;
  }
if (y>=4) t=1;
if (t==0) cout << "yes" << endl;
if (t==1) cout << "no" << endl;
}
