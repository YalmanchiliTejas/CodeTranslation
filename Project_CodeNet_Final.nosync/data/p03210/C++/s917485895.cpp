#include<bits/stdc++.h>
#define rep(i, n) for(int (i)=0 ;i <(n); ++(i))
#define REP(i,m,n) for(int (i) = (m); (i) <= (n); ++(i))
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)? "YES":"NO")
typedef long long ll;
using namespace std;
bool f(int x) {
  if(x == 7 || x == 5 || x == 3) return true; 
  else return false;
}
int main() {
  int x;
  cin >> x;
  YORN(f(x)); 
  return 0;
}