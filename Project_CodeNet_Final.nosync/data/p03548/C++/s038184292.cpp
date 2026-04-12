#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
#define p(x) cout<<(x)<<endl

int main() {
  int x, y, z; cin >> x >> y >> z;
  int i = 0;
  
  while(x >= (i*y + (i+1)*z)) {
    i++;
  }
  
  p(i-1);
}
