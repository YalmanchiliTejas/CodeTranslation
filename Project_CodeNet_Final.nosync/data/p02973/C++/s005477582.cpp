#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>
#include <bitset>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

int main(){
  int N; cin >> N;
  vector<ll> a(N); rep(i, N) cin >> a[i];

  deque<ll> dq;
  rep(i, N){
    int index = lower_bound(dq.begin(), dq.end(), a[i]) - dq.begin();
    if (index == 0) dq.push_front(a[i]);
    else dq[index - 1] = a[i];
  }
  cout << dq.size() << endl;
}
