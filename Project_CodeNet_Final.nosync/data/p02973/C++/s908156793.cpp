#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<int> AA(N, -1);
  REP(i, N){
    int a; cin >> a;
    auto itr = lower_bound(AA.begin(), AA.end(), a);
    itr--;
    *itr = a;
  }
  int ans = AA.end() - upper_bound(AA.begin(), AA.end(), -1);
  cout << ans << endl;
}