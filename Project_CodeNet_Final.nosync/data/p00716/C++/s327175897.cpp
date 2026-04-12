#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define loop(i,a,b) for(int i=(a); i<(int)(b); i++)
#define rep(i,b) loop(i,0,b)
#define all(c) (c).begin(), (c).end()
 
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  int m; cin >> m;
  while(m--) {
    int money, y, n; cin >> money >> y >> n;
    int ans = -1<<31;
    while(n--) {
      int type, fee;
      double interest;
      cin >> type >> interest >> fee;
      int sum = money, isum = 0;
      for(int i = 0; i < y; i++) {
        if(type == 0) {
          isum += sum * interest;
          sum -= fee;
        } else {
          sum += sum * interest - fee;
        }
      }
      sum += isum;
      ans = max(ans, sum);
    }
    cout << ans << endl;
  }
}