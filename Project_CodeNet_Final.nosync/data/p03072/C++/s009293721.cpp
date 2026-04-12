#include <iostream>
#include <string>
#include <vector>
#include <deque>
#define range(i, r) for(int i=0;i<r;i++)
#define ranges(i, l, r) for(int i=l;i<r;i++)
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
#define MODn 1000000009;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  int N, ans=1;
  std::cin >> N;
  std::vector<int> yama(N);
  range(i, N) std::cin >> yama[i];
  ranges(i, 1, N){
    int flag = 1;
    range(j, i){
      if(yama[i]<yama[j]) flag=0;
    }
    if(flag==1) ans++;
  }
  std::cout << ans << '\n';
  return 0;
}
