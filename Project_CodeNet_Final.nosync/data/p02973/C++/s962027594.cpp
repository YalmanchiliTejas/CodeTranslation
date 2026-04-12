#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
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
  rep(i,N) cin >> A[i];

  deque<int> deq;
  for(int i=0; i <N;i++){
    // A[i]以上の値をもつ下限
    int p = lower_bound(deq.begin(), deq.end(), A[i]) - deq.begin();
    if(p==0) deq.push_front(A[i]);
    else deq[p-1] = A[i];
  }

  cout << deq.size() << endl;

  return 0;
}

