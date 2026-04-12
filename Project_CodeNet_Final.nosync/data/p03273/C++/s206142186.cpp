#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define INF 2e8
#define all(a) a.begin(), a.end()
#define pb push_back
#define maxer max_element
#define miner min_element

int main() {
  int nHeight, nWidth;
  cin >> nHeight >> nWidth;

  /*マス目の情報を読み込み，横方向の白線を除去*/
  vector<string> vcTableFiltered;
  rep(i, nHeight) {
    const string strWhite(nWidth, '.');
    string strInput;
    cin >> strInput;
    if (strInput != strWhite) {
      vcTableFiltered.pb(strInput);
    }
  }
  int nHeightNew = vcTableFiltered.size();

  /*縦方向の白線の位置を列挙*/
  unordered_set<int> stPositionWhite;
  rep(j, nWidth) {
    bool fAllWhite = true;
    rep(i, nHeightNew) {
      if (vcTableFiltered[i][j] != '.') {
        fAllWhite = false;
      }
    }
    if (fAllWhite) {
      stPositionWhite.emplace(j);
    }
  }

  /*答えを出力*/
  rep(i, nHeightNew) {
    rep(j, nWidth) {
      if (not stPositionWhite.count(j))
        cout << vcTableFiltered[i][j];
    }
    cout << endl;
  }
}
