#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
  
int main()
{
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;

  int MIN = A*X+B*Y;
  REP(i,max(X,Y)+1){
    int a = max(X-i,0);
    int b = max(Y-i,0);
    MIN = min(MIN,2*i*C+A*a+B*b);
  }  
  cout << MIN << endl;
}