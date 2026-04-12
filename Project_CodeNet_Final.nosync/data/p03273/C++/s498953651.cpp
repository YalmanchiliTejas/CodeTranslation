#include <bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<"="<<x
#define nl cout<<"\n"
#define fr(i,n) for(int i = 0;i < n;i++)
#define pb push_back
using namespace std;

int main() {
  int h,w;
  cin>>h>>w;
  char a[h][w];
  vector<bool> rows(h, true), cols(w, true);
  fr(i,h){
    fr(j,w) {
      cin>>a[i][j];
    }
  }
  fr(i,h) {
    bool hash = false;
    fr(j,w) {
      if(a[i][j] == '#') {
        hash = true;
        break;
      }
    }
    if(!hash) rows[i] = false;
  }

  fr(j,w) {
    bool hash = false;
    fr(i,h) {
      if(a[i][j] == '#') {
        hash = true;
        break;
      }
    }
    if(!hash) cols[j] = false;
  }

  fr(i,h) {
    if(!rows[i]) continue;
    fr(j,w) {
      if(!cols[j]) continue;
      cout<<a[i][j];
    }
    nl;
  }
}