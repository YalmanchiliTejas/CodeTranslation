//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <map>
#include <cmath>
#include <stack>

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
  int a, b, c;
  int x, y;
  int ans = 0;

  cin >> a >> b >> c >> x >> y;
  if(x > y){
    int work = y;
    y = x;
    x = work;
    work = b;
    b = a;
    a = work;
  }
  // 作れるだけ作る
  ans += min(a + b, c * 2) * x;
  // 余ってしまった分を作る
  y -= x;
  ans += min(b, c * 2) * y;
  cout << ans << endl;
  return 0;
}
