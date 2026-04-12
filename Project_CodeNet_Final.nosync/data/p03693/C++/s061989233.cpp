#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
using namespace std;
typedef long long ll;

int main(){
  ll r,g,b;
  cin >> r >> g >> b;
  string ans = ((g*10+b)%4==0) ? "YES" : "NO";
  cout << ans << endl;
  return 0;
}
