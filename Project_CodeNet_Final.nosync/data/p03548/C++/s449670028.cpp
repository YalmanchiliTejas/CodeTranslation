
#include <cstdio>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;
int main(void) {
  ll x, y, z;
  scanf("%lld%lld%lld", &x, &y, &z);
  for(int i = 0; ; ++i) {
    if(y*i+z*(i+1) > x) {
      printf("%d\n", i-1);
      break;
    }
  }
  return 0;
}
