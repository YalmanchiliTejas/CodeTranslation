#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

#define rep(i,b,e) for (int (i) = (b); (i) < (e); (i)++)
typedef long long ll;


int vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
} 

using namespace std;

int main() {
    ll H, W;
    cin >> H >> W;

    vector<string> a(H);

    rep(i,0,H) {
        cin >> a[i];
    }

    // 行の削除
    vector<int> del_row;
    rep(i,0,H) {
        bool all_white = true;
        rep(j, 0, W) {
            //cout << a[i][j] << endl;
            if (a[i][j] == '#') {
                all_white = false;
                break;
            }
        }
        if (all_white) del_row.push_back(i);
    }

    // 列の削除
    vector<int> del_col;
    rep(j,0,W) {
        bool all_white = true;
        rep(i, 0, H) {
            //cout << a[i][j] << endl;
            if (a[i][j] == '#') {
                all_white = false;
                break;
            }
        }
        if (all_white) del_col.push_back(j);
    }

    rep(i, 0 , H) {
        if (vector_finder(del_row, i)) continue;
        rep(j, 0 , W) {
            if (vector_finder(del_col, j)) continue;
            cout << a[i][j];
        }
        cout << endl;
    }

}