#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;
vector<int> to[100005];

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  
  int mini = a * x + b * y;
  for (int i = 1; i <= 100000; i++)
  {
      /* code */
      if (2 * c * i + max(x-i, 0) * a + max(y-i, 0) * b < mini)
      {
          /* code */
          mini = 2 * c * i + max(x-i, 0) * a + max(y-i, 0) * b;
        //   cout << mini << endl;
      }
  }
  

  cout << mini << endl;
  return 0;
}