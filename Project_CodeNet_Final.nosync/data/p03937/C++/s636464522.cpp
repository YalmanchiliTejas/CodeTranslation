#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#define range(i, r) for(int i=0;i<r;i++)
#define ranges(i, l, r) for(int i=l;i<r;i++)
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
#define MODn 1000000009
typedef long long int ll;
using namespace std;


int main(int argc, char const *argv[]) {
  ll x, y, H, W, flag;
  std::cin >> H >> W;
  std::vector<string> a(H);
  range(i, H) std::cin >> a[i];
  a[0][0] = '.';
  for(int i=0;i<1<<(H+W-2);i++){
    x = y = 0, flag = 1;
    for(int j=0;j<(H+W-2);j++){
      ll tes = ((i + (1<<(H+W-2))) >> (H+W-3-j));
      if(tes%2==0){
        x++;
        if(y>=W||x>=H) {
          flag = 0;
          continue;
        }
        if(a[x][y] != '#') flag = 0;
      }else{
        y++;
        if(y>=W||x>=H) {
          flag = 0;
          continue;
        }
        if(a[x][y] != '#') flag = 0;
      }
    }
    if(flag==1){
      x = y = 0;
      for(int j=0;j<(H+W-2);j++){
        ll tes2 = ((i + (1<<(H+W-2))) >> (H+W-3-j));
        if(tes2%2==0){
          x++;
          a[x][y] = '.';
        }else{
          y++;
          a[x][y] = '.';
        }
      }
    }
  }
  flag = 1;
  range(i, H) range(j, W) if(a[i][j]=='#') flag = 0;
  std::cout << (flag==1?"Possible":"Impossible") << '\n';
  return 0;
}
