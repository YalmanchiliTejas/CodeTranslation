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
  int N;
  cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  ll cnt = 0;
  while(1) {
    bool cont = false;
    for (int i = 0; i < N; i++) {
      if (A[i] >= N) {
        cont = true;
      }
    }
    if (!cont) break;
    ll ma_i = max_element(all(A)) - A.begin();
    ll ma = A[ma_i];
    cnt += ma / N;
    for (int i = 0; i < N; i++) {
      if (i == ma_i) {
        A[i] = ma % N;
      } else {
        A[i] += ma / N;
      }
    }

  }
  cout << cnt << endl;
  return 0;
}