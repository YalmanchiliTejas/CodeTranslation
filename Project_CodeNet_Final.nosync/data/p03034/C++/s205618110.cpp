
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int N;
  cin >> N;
  static int s[101010];
  for (int i = 0; i < N - 1; i++) cin >> s[i];

  int ans = 0;
  for (int d = 1; d < N; d++) {
    int sum = 0;
    int L = 0, R = N - 1;

    //割り切れるとき、ＬとＲは途中で等しくなる。等しくなったときに足すのをやめる。
    if ((N - 1) % d == 0) {
      while (L < R) {
        sum += s[L] + s[R];
        L += d;
        R -= d;
        ans = max(ans, sum);
      }

      //割り切れないとき、ＬとＲは全て異なる。Ｌ+dがＮ－１を越えない範囲で足し続ける。
      //L==N-1を含めないことに注意。含めてしまうとＲ＝Ｎ－１と同じマスを踏むことになる。
    } else {
      while (L + d < N - 1) {
        sum += s[L] + s[R];
        L += d;
        R -= d;
        ans = max(ans, sum);
      }
    }
  }

  cout << ans << endl;
  return 0;
}
