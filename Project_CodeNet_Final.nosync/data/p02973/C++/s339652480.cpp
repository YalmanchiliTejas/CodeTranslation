#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))
#define rep(i,a,b) for(int (i)=int(a);(i)<int(b);(i)++)
#define rrep(i,a,b) for(int (i)=int(a);(i)>=int(b);(i)--)

#define put(a) cout << (a) << endl

#define INF 1000000001
#define MOD 1000000007
#define INF64 1000000000000000001

#define F first
#define S second

#define Pii  pair<int,int>
#define Pll  pair<long long,long long>
#define Piii pair<int,pair<int,int>>
#define Plll pair<long long,pair<long long,long long>>

#define Vll(a,b,c)    vector<vector<long long>> (a)((b),vector<long long>((c))
#define Vlll(a,b,c,d) vector<vector<vector<long long>>> (a)((b),vector<vector<long long>>((c),vector<long long>((d)))

#define MAX_N 100000

int main (void)
{
  int ans;
  int N;

  cin >> N;

  int A[N];

  rep(i,0,N) {
    cin >> A[i];
  }

  //広義単調減少列の最大長が答え
  //dp[i] 最後がA[i]の最大長
  // int dp[N];
  //
  // dp[0] = 1;
  // ans = 1;
  // rep(i,0,N) {
  //   dp[i] = 1;
  //   rep(j,0,i) {
  //     if (A[j] >= A[i]) {
  //       dp[i] = max(dp[i],dp[j]+1);
  //     }
  //   }
  //   ans = max(ans,dp[i]);
  // }

  //dp[i] i+1の長さになる最大の最後の値
  vector<int> v;

  rep(i,0,N) {
    A[i] = -A[i];
    auto itl = upper_bound(v.begin(),v.end(),A[i]);
    if(itl == v.end()) {
      v.push_back(A[i]);
    } else {
      *itl = A[i];
    }
  }

  ans = v.size();
  cout << ans << endl;

  return 0;
}
