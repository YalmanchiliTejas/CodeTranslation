#include <bits/stdc++.h>
#define FOR(i, k, n) for(int i = (k); i < (n); i++)
#define FORe(i, k, n) for(int i = (k); i <= (n); i++)
#define FORr(i, k, n) for(int i = (k); i > (n); i--)
#define FORre(i, k, n) for(int i = (k); i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using ll = long long;

const int INF = 1001001001;
const int mod = 1000000007;

int main(void){
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];

  deque<int> dq;
  REP(i, n){
    auto p = lower_bound(ALL(dq), a[i]);
    if(p == dq.begin()){
      dq.push_front(a[i]);
    }else{
      *(p-1) = a[i];
    }
  }
  cout << dq.size() << endl;
  return 0;
}