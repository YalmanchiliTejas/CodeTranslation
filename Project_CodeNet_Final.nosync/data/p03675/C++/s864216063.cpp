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
  vector<int> A(N);
  REP(i, N){
    cin >> A[i];
  }
  deque<int> B;
  if(N%2 == 0){
    REP(i, N){
      if(i%2 == 1){
        B.push_front(A[i]);
      }else{
        B.push_back(A[i]);
      }
    }
  }else{
    REP(i, N){
      if(i%2 == 0){
        B.push_front(A[i]);
      }else{
        B.push_back(A[i]);
      }
    }
  }
  REP(i, N){
    cout << B.front();
    if(i != N-1){
      cout << " ";
    }else{
      cout << endl;
    }
    B.pop_front();
  }
}
