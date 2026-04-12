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

int main() {
  int N;
  cin>>N;
  ll A[N], sumA[N+1];
  for(int i=0;i<N;++i) {
    cin>>A[i];
    sumA[i+1] = A[i];
  }
  for(int i=1;i<=N;++i) {
    sumA[i] += sumA[i-1];
    sumA[i] %= mod;
  }
  ll ans = 0;
  for(int i=0;i<N;++i) {
    ans += A[i]*(sumA[N]-sumA[i+1]+mod)%mod;
    ans %= mod;
  }
  cout<<ans<<endl;
}

