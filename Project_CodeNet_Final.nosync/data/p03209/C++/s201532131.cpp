#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

int64 ans;
vector<int64> patty; // バーガーNのパティの枚数
vector<int64> sheet; // バーガーNの層の数


// バーガーNの、下からlayer層目
void burger(int N, int64 layer) {
  if (layer == 1) {
    if (N == 0) {
      ans++;
      return;
    } else {
      return;
    }
  }
  else if (layer <= sheet[N - 1] + 1) {
    burger(N - 1, layer - 1);
  }
  else if (layer == sheet[N - 1] + 2) {
    ans += patty[N - 1] + 1;
    // cerr << "ans:" << ans << "\n";
    // cerr << "pattern 1" << "\n";
    return;
  }
  else if (layer <= 2 * sheet[N - 1] + 2) {
    ans += patty[N - 1] + 1;
    // cerr << "ans:" << ans << "\n"; 
    // cerr << "pattern 2" << "\n";
    burger(N - 1, layer - sheet[N - 1] - 2);
  }
  else if (layer == 2 * sheet[N - 1] + 3) {
    ans += 2 * patty[N - 1] + 1;
    //cerr << "ans:" << ans << "\n"; 
    //cerr << "pattern 3" << "\n";
    return;
  } else {
    //cout << "error" << "\n";
    return;
  }
}

int main() {
  int N; int64 X; cin >> N >> X;
  
  /* 
  vector<string> S(N + 1);
  S[0] = "P";
  for (int i = 1; i <= N; i++) {
    S[i] = "B" + S[i - 1] + "P" + S[i - 1] + "B";
    cerr << S[i] << endl;;
  }
  return 0;
  */

  patty.resize(N + 1); // バーガーNのパティの枚数
  patty[0] = 1;
  sheet.resize(N + 1); // バーガーNの層の数
  sheet[0] = 1;

  for (int i = 1; i <= N; i++) {
    patty[i] = 2 * patty[i - 1] + 1;
    sheet[i] = 2 * sheet[i - 1] + 3;
  }

  burger(N, X);

  cout << ans << endl;
}
