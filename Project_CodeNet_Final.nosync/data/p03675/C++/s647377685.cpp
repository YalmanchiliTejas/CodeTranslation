#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> b(n);
  int l = 0, r = n - 1;
  for(int i = n - 1; i >= 0; --i) {
    if(i % 2 == (n - 1) % 2) {
      b[l] = a[i];
      ++l;
    }else{
      b[r] = a[i];
      --r;
    }
  }

  REP(i,n) {
    if(i) cout << " ";
    cout << b[i];
  }
  cout << endl;
  return 0;
}

