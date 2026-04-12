#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  int N;
  cin >> N;
  vector<int> A, B;
  rep(i,N){
    int a;
    cin >> a;
    A.push_back(a);
    B.push_back(a);
  }
  sort(ALLOF(B));

  int x = B[B.size()/2-1];
  int y = B[B.size()/2];
 
  rep(i,N){
    if(x < A[i]) cout << x << endl;
    else cout << y << endl;
  }
  
  return 0;
}

