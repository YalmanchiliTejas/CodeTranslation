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
  ll N, X, M;
  cin>>N>>X>>M;
  map<ll, ll> amap;
  ll ans = 0;
  ll num;
  ll cycle;
  vector<ll> sum;
  bool ok = true;
  for(ll i=0;i<N;++i) {
    sum.push_back(X);
    if(sum.size()>1) sum[sum.size()-1] += sum[sum.size()-2];
    if(amap[X]>0) {
      num = i;
      cycle = amap[X];
      ok = false;
      break;
    }
    amap[X] = i;
    ans += X;
    X = X*X%M;
  }
  if(ok) {
    cout<<ans<<endl;
    return 0;
  }
  ll tmp = sum[num-1] - sum[cycle-1];
  ans += (N-num)/(num-cycle)*tmp;
  ll K = (N-num)%(num-cycle);
  for(ll i=0;i<K;++i) {
    ans += X;
    X = X*X%M;
  }
  cout<<ans<<endl;
}

