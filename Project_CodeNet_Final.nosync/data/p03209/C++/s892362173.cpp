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

ll N, X;
ll length[55];

ll solve(ll L, ll t) {
  if(L==0) {
    if(t==1) return 1;
    else return 0;
  }
  if(t==0) return 0;
  else if(t<=1+length[L-1]) {
    return solve(L-1, t-1);
  }
  else if(t<=2+length[L-1]) {
    return 1 + solve(L-1, length[L-1]);
  }
  else if(t<=2+2*length[L-1]) {
    return solve(L-1, length[L-1]) + 1 + solve(L-1, t-2-length[L-1]);
  }
  else {
    return 1 + 2*solve(L-1, length[L-1]);
  }
}

int main() {
  length[0] = 1;
  for(int i=1;i<55;++i) {
    length[i] = 2*length[i-1]+3;
  }
  cin>>N>>X;
  cout<<solve(N, X)<<endl;
}

