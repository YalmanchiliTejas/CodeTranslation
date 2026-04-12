#include "bits/stdc++.h"
using namespace std;
#define FOR(i,a,b) for(int i =(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define REPS(i,n) for(int i=1;i<=(n);i++)
#define RREPS(i,n) for(int i=(n);i>0;i--)
#define mp make_pair
#define pb(a) push_back(a)
typedef long long ll;

int main(){
  int N;
  cin >> N;
  vector<int> X(N);
  vector<int> Y(N);
  REP(i,N){
    cin >> X[i];
    Y[i] = X[i];
  }
  sort(Y.begin(),Y.end());
  if(N == 2){
    cout << X[1] << endl;
    cout << X[0] << endl;
    return 0;
  }
  int a,b,c,d;
  a = Y[N/2-1];
  b = Y[N/2];
  REP(i,N){
    if(X[i] <= a) cout << b << endl;
    else cout << a << endl;
  }
  return 0;
}
