#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

char c[] = {'S','W'};
int v0[] = {0,0,1,1};
int v1[] = {0,1,0,1};
int main() {
  int n; string s;
  cin >> n >> s;
  vector<int> v;
  auto f = [&](int v0,int v1){
    v = vector<int>(n+1);
    v[0]=v0,v[1]=v1;
    rep(i,n-1){
      if(v[i+1]==0&&s[i+1]=='o') v[i+2] = v[i];
      if(v[i+1]==1&&s[i+1]=='x') v[i+2] = v[i];
      if(v[i+1]==0&&s[i+1]=='x') v[i+2] = (v[i]^1);
      if(v[i+1]==1&&s[i+1]=='o') v[i+2] = (v[i]^1);
    }
    if(v[0]!=v[n]) return false;
    if(v[0]==0&&s[0]=='o') return v[n-1] == v[1];
    if(v[0]==1&&s[0]=='x') return v[n-1] == v[1];
    if(v[0]==0&&s[0]=='x') return v[n-1] == (v[1]^1);
    if(v[0]==1&&s[0]=='o') return v[n-1] == (v[1]^1);
    return false;
  };
  rep(i,4){
    if(f(v0[i],v1[i])){
      rep(i,n) cout << c[v[i]]; cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}