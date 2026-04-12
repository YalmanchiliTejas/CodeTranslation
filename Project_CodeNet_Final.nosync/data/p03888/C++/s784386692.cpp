#include <bits/stdc++.h>

#define mp       make_pair
#define mt	  make_tuple
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF=1<<29;
const double EPS=1e-9;
const ll MOD = 1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
double R1,R2;
int main(){
  cin >> R1 >> R2;
  double res = (R1 * R2) / (R1 + R2);
  printf("%.20lf\n", res);
  return 0;
}
