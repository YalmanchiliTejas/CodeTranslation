#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true; } return false; }

//INT_MAX	2,147,483,647 = 2*1.0e9

int main(){
  int N;
  cin >> N;

  vector<int> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];

  deque<int> q;
  q.push_front(A[0]);
  for(int i = 1; i < N; i++){
    int pos = lower_bound(q.begin(), q.end(), A[i]) - q.begin();
    if(pos == 0) q.push_front(A[i]);
    else q[pos-1] = A[i];
  }

  int ans = q.size();

  cout << ans << endl;

  return 0;
}
