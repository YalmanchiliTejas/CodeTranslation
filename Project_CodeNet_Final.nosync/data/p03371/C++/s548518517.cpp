#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int ans = 1000000000;
  int mx = max(x, y);
  for (int i = 0; i <= mx; i++) {
    int tx = max(x - i, 0) * a;
    int ty = max(y - i, 0) * b;
    int tc = i * 2 * c;
    ans = min(ans, tx + ty + tc);
  }
  cout<<ans<<endl;
  return 0;
}
