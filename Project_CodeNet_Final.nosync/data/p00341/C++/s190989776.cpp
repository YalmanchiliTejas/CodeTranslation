#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

int main() {
  int a[12];
  map<int,int> mp;
  rep(i,12) {
    cin >> a[i];
    ++mp[a[i]];
  }
  rep(i,12) rep(j,12) {
    map<int,int> mp2 = mp;
    mp2[a[i]] -= 4;
    mp2[a[j]] -= 4;
    if( mp2[a[i]] < 0 || mp2[a[j]] < 0 ) {
      continue;
    }
    map<int,int> counter;
    int key = -1;
    for(auto v : mp2) {
      if( v.second > 0 ) {
        counter[v.first] += v.second;
        key = v.first;
      }
    }
    if( counter.size() != 1 ) continue;
    if( counter[key] == 4 ) {
      puts("yes");
      return 0;
    }
  }
  puts("no");
  return 0;
}