#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
//constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;
long double A, B, H, M;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  vector<int> cnt(N, 0);
  // a > b < c > 
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
  ll sum = 0;
  REP(i, N){
    sum += (ll)cnt[i]*A[i];
  }
  ll ans = sum;
  // a < b > c < 
  REP(i, N){
    cnt[i] = 0;
  }
  REP(i, N-1){
    if(i%2){
      cnt[i]++;
      cnt[i+1]--;
    }
    else{
      cnt[i]--;
      cnt[i+1]++;
    }
  }
  sort(cnt.begin(), cnt.end());
  sum =0;
  REP(i, N){
    sum += (ll)cnt[i]*A[i];
  }
  ans = max(ans, sum);
  cout << ans << endl;
  return 0;
}
