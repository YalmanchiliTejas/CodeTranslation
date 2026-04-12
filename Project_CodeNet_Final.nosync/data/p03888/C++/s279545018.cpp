#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;

int main(){
  ld R1, R2;
  cin >> R1 >> R2;
  ld R = R1 * R2 / (R1 + R2);
  cout << fixed << setprecision(10) << R << endl;
  return 0;
}

