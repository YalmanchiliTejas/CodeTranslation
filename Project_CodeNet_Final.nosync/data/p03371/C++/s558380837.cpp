#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9+7;

int a, b, c, x, y;
int pyen(int x, int y){
  if(x==y) return min(a, b);
  else if(x>y) return a;
  else return b;
}
 
int main(){
  cin >> a >> b >> c >> x >> y;

  cout << min({a*x+b*y, 2*c*max(x, y), 2*c*min(x, y)+abs(x-y)*pyen(x, y)}) << endl;

  return 0;
}
