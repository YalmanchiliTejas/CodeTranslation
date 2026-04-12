#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;
#define end _____end
#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

Int dp[216000];
Int l[216000], r[216000], a[216000];
Int n, m;
vector<P> Interval[216000];
vector<Int> add[216000], end[216000];
Int seg[1 << 20];
Int all[1 << 20];
void addval(Int l, Int r, Int val, Int bottom = 0, Int top = (1<<19), Int pos = 1){
  if(r <= bottom || top <= l)return;
  if(l <= bottom && top <= r){
    all[pos] += val;
    return;
  }
  Int mid = (bottom + top ) / 2;
  addval(l, r, val, bottom, mid, pos * 2);
  addval(l, r, val, mid, top, pos * 2+1);
  seg[pos] = max(seg[pos * 2] + all[pos * 2],
		 seg[pos * 2 + 1] + all[pos * 2 + 1]);
}

Int getval(Int l, Int r, Int bottom = 0, Int top = 1 << 19, Int pos = 1){
  if(r <= bottom || top <= l)return -LINF;
  if(l <= bottom && top <= r){
    return seg[pos] + all[pos];
  }
  Int mid = (bottom + top) / 2;
  Int res = getval(l, r, bottom, mid, pos * 2);
  Int res2 = getval(l, r, mid, top, pos * 2 + 1);
  return max(res, res2) + all[pos];
}


int main(){
  cin >> n >> m;
  for(Int i = 0;i < m;i++){
    cin >> l[i] >> r[i] >> a[i];
    add[l[i]].push_back(i);
    end[r[i]].push_back(i);
  }
  dp[0] = 0;
  for(Int i = 1;i <= n;i++){
    for(Int j = 0;j < add[i].size();j++){
      Int id = add[i][j];
      addval(0, l[id], a[id]);
      //      cout << "add " << l[id] << " " << a[id] << endl;
    }
    dp[i] = getval(0, i);
    //    cout << i << " " << dp[i] << endl;
    for(Int j = 0;j < end[i].size();j++){
      Int id = end[i][j];
      addval(0, l[id], -a[id]);
      ///      cout << "add " << l[id] << " " << -a[id] << endl;
    }
    addval(i, i+1, dp[i]);
  }
  cout << getval(0,n+1) << endl;
  return 0;
}