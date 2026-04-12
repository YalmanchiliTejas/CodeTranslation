#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;

int main(){
  int N;
  cin >> N;
  vector<int> X(N);
  REP(i, N) cin >> X[i];

  vector<int> Y(X);
  sort(ALL(Y));
  REP(i,N){
    if(X[i] <= Y[N / 2 - 1]) cout << Y[N / 2];
    else cout << Y[N / 2 - 1];
    cout << endl;
  }
  return 0;
}

