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
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N;
  cin>>N;
  vector<ll> A(N);
  for(int i=0;i<N;++i) cin>>A[i];
  sort(A.begin(), A.end());
  ll ans, tmpans;
  if(N%2==0) {
    ans = 0;
    for(int i=0;i<N;++i) {
      if(i<N/2) {
        if(i==N/2-1) ans -= A[i];
        else ans -= A[i]*2;
      }
      else {
        if(i==N/2) ans += A[i];
        else ans += A[i]*2;
      }
    }
  }
  else {
    ans = 0;
    for(int i=0;i<N;++i) {
      if(i<N/2) ans -= A[i]*2;
      else {
        if(i==N/2 || i==N/2+1) ans += A[i];
        else ans += A[i]*2;
      }
    }
    tmpans = 0;
    for(int i=0;i<N;++i) {
      if(i>N/2) tmpans += A[i]*2;
      else {
        if(i==N/2 || i==N/2-1) tmpans -= A[i];
        else tmpans -= A[i]*2;
      }
    }
    ans = max(ans, tmpans);
  }
  cout<<ans<<endl;
}

