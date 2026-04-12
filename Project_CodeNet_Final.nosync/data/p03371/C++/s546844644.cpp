#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

template <typename T>
bool chmax(T &a, T &b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T>
bool chmin(T &a, T &b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}


ll A[110][110];

int main() {
  ll A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  ll ans = 0;
  if(A+B > 2*C) {
    ans += min(X,Y) * 2 * C;
    int x = X;
    int y = Y;
    X -= min(x,y);
    Y -= min(x,y);
    // cout << X << ":" << Y << endl;
    ans += min(X*A + Y*B,X*2*C + Y*2*C);
  }
  else {
    ans += X*A + Y*B;
  }
  cout << ans << endl;
  return 0;
}



