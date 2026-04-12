#include<bits/stdc++.h>
using namespace std;
int main() {
  int h,w,i,j;
  cin>>h>>w;
  vector<vector<char>> a(h,vector<char>(w));
  vector<int> r(h),c(w);
  for (i=0;i<h;i++) for (j=0;j<w;j++) cin>>a.at(i).at(j);
  for (i=0;i<h;i++) {
    for (j=0;j<w;j++) if (a.at(i).at(j)=='#') break;
    if (j==w) r.at(i)=1;
  }
  for (j=0;j<w;j++) {
    for (i=0;i<h;i++) if (a.at(i).at(j)=='#') break;
    if (i==h) c.at(j)=1;
  }
  for (i=0;i<h;i++) {
    if (r.at(i)==0) {
      for (j=0;j<w;j++) if (c.at(j)==0) cout<<a.at(i).at(j);
      cout<<endl;
    }
  }
} 