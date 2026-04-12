#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >=0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
 
typedef long long ll;
#define INF 1e9


int main(){
  int N;
  cin >> N;
  vector<int> X(N), B(N);
  REP(i, N){
    cin >> X[i];
    B[i] = X[i];
  }
  sort(X.begin(), X.end());
  int media = N / 2 -1;
  int medib = N / 2;
  REP(i, N){
    if(B[i] > X[media]){
      cout << X[media] << endl;
    }
    else{
      cout << X[medib] << endl;
    }
  }


  return 0;
}