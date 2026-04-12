#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

map<pair<int, int>, ll> DP;

int main() {
  int N;
  cin>>N;
  for(int i=0;i<N;++i) {
    DP[mp(i, i/2)] = -big;
    DP[mp(i, i/2+1)] = -big;
  }
  ll A[N];
  for(int i=0;i<N;++i) cin>>A[i];
  DP[mp(0, 1)] = A[0];
  DP[mp(1, 1)] = A[1];
  map<pair<int, int>, int> amap;
  amap[mp(0, 1)] = 1;
  amap[mp(1, 1)] = 1;
  for(int i=2;i<N;++i) {
    if(amap[mp(i-2, i/2-1)]>0 && amap[mp(i-3, i/2-1)]>0) {
      DP[mp(i, i/2)] = max(DP[mp(i, i/2)], A[i] + max(DP[mp(i-2, i/2-1)], DP[mp(i-3, i/2-1)]));
    }
    else if(amap[mp(i-2, i/2-1)]>0) {
      DP[mp(i, i/2)] = max(DP[mp(i, i/2)], A[i] + DP[mp(i-2, i/2-1)]);
    }
    else if(amap[mp(i-3, i/2-1)]>0) {
      DP[mp(i, i/2)] = max(DP[mp(i, i/2)], A[i] + DP[mp(i-3, i/2-1)]);
    }
    else {
      DP[mp(i, i/2)] = max(DP[mp(i, i/2)], A[i]);
    }
    amap[mp(i, i/2)] = 1;
    if(amap[mp(i-2, i/2)]>0 && amap[mp(i-3, i/2)]>0) {
      DP[mp(i, i/2+1)] = max(DP[mp(i, i/2+1)], A[i] + max(DP[mp(i-2, i/2)], DP[mp(i-3, i/2)]));
    }
    else if(amap[mp(i-2, i/2)]>0) {
      DP[mp(i, i/2+1)] = max(DP[mp(i, i/2+1)], A[i] + DP[mp(i-2, i/2)]);
    }
    else if(amap[mp(i-3, i/2)]>0) {
      DP[mp(i, i/2+1)] = max(DP[mp(i, i/2+1)], A[i] + DP[mp(i-3, i/2)]);
    }
    else {
      DP[mp(i, i/2+1)] = max(DP[mp(i, i/2+1)], A[i]);
    }
    amap[mp(i,  i/2+1)] = 1;
  }
  cout<<max(DP[mp(N-1, N/2)], DP[mp(N-2, N/2)])<<endl;
}
