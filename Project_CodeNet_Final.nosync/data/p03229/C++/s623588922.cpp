#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
// constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;




int main(){
  int N;
  cin >> N;
  vector<int> A(N), cnt(N, 0);
  REP(i, N){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  REP(i, N-1){
    if(i % 2){
      cnt[i]++;
      cnt[i+1]--;
    }
    else{
      cnt[i]--;
      cnt[i+1]++;
    }
  }
  ll ans = 0, sum = 0;
  sort(cnt.begin(), cnt.end());
  REP(i, N){
    sum += cnt[i] * A[i];
  }
  ans = sum;
  sum = 0;
  REP(i, N){
    cnt[i] = 0;
  }
  REP(i, N-1){
    if(i % 2){
      cnt[i]--;
      cnt[i+1]++;
    }
    else{
      cnt[i]++;
      cnt[i+1]--;
    }
  }
  sort(cnt.begin(), cnt.end());
  sum = 0;
  REP(i, N){
    sum += cnt[i] * A[i];
  }
  ans = max(ans, sum);
  cout << ans << endl;
  return 0;
}