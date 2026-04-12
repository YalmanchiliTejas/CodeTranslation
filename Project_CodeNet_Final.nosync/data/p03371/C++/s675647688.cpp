#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
  
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
  
using namespace std;
  
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
  
const int INF=1<<29;
const double EPS=1e-9;
  
const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};
int main() {
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  X *= 2, Y *= 2;
  ll ans = 1LL << 60;
  for(int c = 0; c <= max(X, Y); c+=2) {
    ll need = c * C + A * (max(0LL, X - c + 1) / 2) + B * (max(0LL, Y - c + 1) / 2);
    ans = min(ans, need);
  }
  cout << ans << endl;
  return 0;
}