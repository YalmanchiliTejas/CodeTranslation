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


int inf = 1e+9;

int main() {
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int ans = inf;
  //ABセットで決め打ち全探索を考える
  rep(i,200000) {
    int cost = max(0,X-i) * A + max(0,Y-i) * B + 2 * C * i;
    ans = min(cost,ans);
  }
  cout << ans << endl;
  return 0;
}



