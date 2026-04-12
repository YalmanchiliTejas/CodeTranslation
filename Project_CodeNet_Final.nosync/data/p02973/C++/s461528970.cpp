#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define INF 1e9
// const ll INF = 1LL << 60;

int N;
vector<int> A;
int main(){
  cin >> N;
  A.resize(N);
  REP(i, N){
    cin >> A[i];
  }
  vector<int> L(N, -1);
  REP(i, N){
    int ng = -1, ok = N-1;
    while(abs(ng-ok) > 1){
      int mid = (ok+ng) /2;
      if(L[mid] < A[i]){
        ok = mid;
      }
      else{
        ng = mid;
      }
    }
    L[ok] = A[i];
  }
  int ans = 0;
  REP(i, N){
    if(L[i] != -1){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

