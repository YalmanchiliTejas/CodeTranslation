#include <iostream>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)

typedef int64_t ll;

const ll INF = 1e18;

const int MAXN = 3001;

int N;
vector<int> a;

ll fmemo[MAXN][MAXN];
ll smemo[MAXN][MAXN];

ll second(int, int);

ll first(int l, int r) { // inclusive
  if (l > r) return 0;
  if (fmemo[l][r] != INF) return fmemo[l][r];

  ll ret = max(second(l + 1, r) + a[l], second(l, r - 1) + a[r]);
  // cout << "first: " << l << " " << r << ", " << ret << endl;
  return fmemo[l][r] = ret;
}

ll second(int l, int r) { // inclusive
  if (l > r) return 0;
  if (smemo[l][r] != INF) return smemo[l][r];

  ll ret = min(first(l + 1, r) - a[l], first(l, r - 1) - a[r]);
  // cout << "second: " << l << " " << r << ", " << ret << endl;
  return smemo[l][r] = ret;
}
int main(){
  cin >> N;
  a.resize(N);
  REP(i,N) cin >> a[i];

  REP(i,MAXN)REP(j,MAXN) fmemo[i][j] = INF;
  REP(i,MAXN)REP(j,MAXN) smemo[i][j] = INF;

  cout << first(0, N-1) << endl;
  return 0;
}

