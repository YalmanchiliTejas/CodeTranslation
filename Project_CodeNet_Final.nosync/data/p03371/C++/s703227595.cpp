#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
typedef long long ll;
using namespace std;
int main()
{
  int a, b, c, x, y;
  cin >> a >> b >> c>> x >> y;
  if(a + b <= 2*c){
    cout << a*x + b*y << endl;
  }else{
    if(x < y){
      int p1 = c*2*x + (y - x)*b;
      int p2 = c*2*y;
      cout << min(p1, p2) << endl;
    }else{
      int p1 = c*2*y + (x - y)*a;
      int p2 = c*2*x;
      cout << min(p1, p2) << endl;
    }
  }
}
