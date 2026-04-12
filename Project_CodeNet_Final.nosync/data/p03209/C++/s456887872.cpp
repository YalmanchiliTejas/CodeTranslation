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

ll L[55];

ll solve(ll N, ll X) {
  if(N==1) {
    if(X<=1) return 0;
    else if(X<=4) return X-1;
    else return 3;
  }
  if(X<=0) {
    return 0;
  }
  else if(X<L[N]/2+1) {
    return solve(N-1, X-1);
  }
  else if(X==L[N]/2+1) {
    return 1+solve(N-1, L[N-1]);
  }
  else if(X<L[N]) {
    return 1 + solve(N-1, L[N-1]) + solve(N-1, X - (2+L[N-1]));
  }
  else {
    return 1 + solve(N-1, L[N-1])*2;
  }
}

int main() {
  ll N, X;
  cin>>N>>X;
  L[1] = 5;
  for(int i=2;i<55;++i) {
    L[i] = L[i-1]*2 + 3;
  }
  cout<<solve(N, X)<<endl;
}

