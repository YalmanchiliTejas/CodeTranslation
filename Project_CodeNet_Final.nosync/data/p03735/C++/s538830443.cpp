///FUCKOUT
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
//#define endl '\n'

using ll = long long;
using db = long double;
using row = vector<int>;
using ii = pair<ll, ll>;

#define int ll

const int N = 2e5+5, M = 1e6 + 5, LG = 17, MOD = 1e6 + 3;
const int BLOCK = 55;
const int BLOCKN = N / BLOCK + 1;
const long double EPS = 1e-7;
using ull = unsigned long long;

int n, x[N], y[N], mxIdx, mnIdx;
ll solve1(int LR,int RR, int LB, int RB){

  f(i,0,n){
    if(i == mnIdx || i == mxIdx)continue;
    RR = max(RR,x[i]);
    LB = min(LB,y[i]);
  }

  assert(LR<=RR);
  assert(LB<=RB);
  return (RR-LR) * 1ll * (RB-LB);
}
int cnt[N];
ll solve2(int LR,int RR, int LB, int RB){
  vector<pair<int,int>> vp;
  f(i,0,n){
    if(i == mnIdx || i == mxIdx)continue;
    vp.emplace_back(x[i], i);
    vp.emplace_back(y[i], i);
  }

  sort(vp.begin(),vp.end());

  int cntD = 0;
  int ans = INT_MAX;
  int sz = vp.size();
  for(int i = sz-1,j=sz-1; i >= 0; --i){

    if(!cnt[vp[i].S])cntD++;
    cnt[vp[i].S]++;
    while(cnt[vp[j].S] == 2){
      cnt[vp[j].S]--;
      --j;
    }

    if(cntD == n - 2)
      ans = min(ans, max(RB,vp[j].F) - min(LB,vp[i].F));

  }
  return 1ll * ans * (RR-LR);
}
int32_t main(){
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  cin >> n;

  f(i,0,n){
    cin >> x[i] >> y[i];
    if(x[i] > y[i])swap(x[i], y[i]);
  }

  f(i,0,n){
    if(y[i] > y[mxIdx]){
      mxIdx = i;
    }
    if(x[i] < x[mnIdx]){
      mnIdx = i;
    }
  }

  if(mxIdx == mnIdx){
    ///same box
    cout<<solve1(x[mnIdx],x[mnIdx],y[mxIdx],y[mxIdx])<<'\n';
  } else {
    cout << min(
                solve1(x[mnIdx],x[mxIdx],y[mnIdx],y[mxIdx]),
                solve2(x[mnIdx],y[mxIdx],min(y[mnIdx],x[mxIdx]),max(y[mnIdx],x[mxIdx]))
                ) << '\n';
  }


  return 0;
}
