#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cassert>
#include <functional>
#include <string>
#include <sstream>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
#define rep(i, j, n) for (int i = j; i < n; i++)
#define out(ans) cout << ans << endl;

/////////////////////////////////////////////////////////

void Main(){
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
  int res = 1000000000;
  rep(i, 0, max(X, Y) + 1){
    int sum = 0;
    sum += C * 2 * i;
    sum += A * max(0, X - i);
    sum += B * max(0, Y - i);
    if(sum < res) res = sum;
  }
  cout << res << endl;
}

/////////////////////////////////////////////////////////

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  //cout << std::fixed << std::setprecision(15);

  Main();
}
