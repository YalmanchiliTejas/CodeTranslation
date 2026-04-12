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

ll solve(ll N, ll X) {
  if(N==1) {
    if(X==1) return 0;
    if(X==2) return 1;
    if(X==3) return 2;
    if(X==4) return 3;
    if(X==5) return 3;
  }
  if(X==1) return 0;
  if(X<=1+pow(2, N+1)-3) return solve(N-1, X-1);
  if(X<=2+pow(2, N+1)-3) return 1+solve(N-1, X-2);
  if(X<=2+2*(pow(2, N+1)-3)) return 1+solve(N-1, pow(2, N+1)-3)+solve(N-1, X-2-(pow(2, N+1)-3));
  return 1+2*solve(N-1, pow(2, N+1)-3);
}

int main() {
  ll N, X;
  cin>>N>>X;
  cout<<solve(N, X)<<endl;
}

