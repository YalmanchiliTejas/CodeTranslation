#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <stack>

#define mod 1000000007
#define INF2 9999999999
#define INF (1<<30)
#define rep(i,n) for(int (i)=0; (i)<(n); (i)++)

using namespace std;
using ll = __int64_t;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int DX[] = {1, 1, 0, -1, -1, -1, 0, 1};
int DY[] = {0, -1, -1, -1, 0, 1, 1, 1};

int n, res=0;
int h[25];

bool ok(int x){
  for(int i = 0; i < x; i++){
    if(h[x] < h[i]){
      return false;
    }
  }
  return true;
}

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> h[i];
  }
  for(int i = 0; i < n; i++){
    if(ok(i)){
      res++;
    }
  }
  cout << res << endl;
}

int main(){
  solve();
  return 0;
}