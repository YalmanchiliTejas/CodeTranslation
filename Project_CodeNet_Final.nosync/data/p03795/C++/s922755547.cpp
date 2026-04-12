#include <bits/stdc++.h>
#define ll long long
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

using namespace std;

int main() {
  INIT;
  
  int n;
  cin >> n;// >> c >> d;
  
  cout << 800*n - 200*(n / 15) << endl;
  
  return 0;
}