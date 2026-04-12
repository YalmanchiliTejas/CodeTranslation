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
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

ll DP[200005][2];

int main() {
  int N;
  cin>>N;
  ll A[N];
  for(int i=0;i<N;++i) cin>>A[i];
  if(N==2) {
    cout<<max(A[0], A[1])<<endl;
    return 0;
  }
  if(N==3) {
    cout<<max(A[0], max(A[1], A[2]))<<endl;
    return 0;
  }
  DP[0][1] = A[0];
  DP[1][1] = A[1];
  DP[2][0] = A[2];
  DP[2][1] = A[0]+A[2];
  for(int i=3;i<N;++i) {
    if(i%2==0) {
      DP[i][1] = DP[i-2][1]+A[i];
      DP[i][0] = max(DP[i-4][1], max(DP[i-3][1], DP[i-2][0])) + A[i];
    }
    else {
      DP[i][1] = max(DP[i-2][1], DP[i-3][1]) + A[i];
    }
  }
  if((N-1)%2==0) cout<<DP[N-1][0]<<endl;
  else cout<<DP[N-1][1]<<endl;
}

