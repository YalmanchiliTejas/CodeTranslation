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
  int H, W;
  std::cin >> H >> W;
  std::vector<string> ans;
  std::vector<int> cols(W, 1);
  range(i, H){
    string s;
    std::cin >> s;
    int flag = 1;
    range(j, W){
      if(s[j]=='#'){
        cols[j] = 0;
        flag = 0;
      }
    }
    if(flag == 0) {
      ans.push_back(s);
    }
  }
  range(i, ans.size()){
    range(j, W){
      if(cols[j] == 0) std::cout << ans[i][j];
    }
    std::cout <<'\n';
  }
  return 0;
}
