#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DICE {
  // 上/正面/裏/右/左

  vector<int> num;
  DICE(vector<int> num = {}) : num(num) {};

  int roll_North() {
    swap(num[0], num[3]);
    swap(num[0], num[2]);
    swap(num[0], num[1]);
    return num[0];
  }

  int roll_South() {
    swap(num[0], num[1]);
    swap(num[0], num[2]);
    swap(num[0], num[3]);
    return num[0];
  }

  int roll_West() {
    swap(num[0], num[5]);
    swap(num[0], num[2]);
    swap(num[0], num[4]);
    return num[0];
  }

  int roll_East() {
    swap(num[0], num[4]);
    swap(num[0], num[2]);
    swap(num[0], num[5]);
    return num[0];
  }

  int roll_Right() {
    swap(num[1], num[5]);
    swap(num[1], num[3]);
    swap(num[1], num[4]);
    return num[0];
  }

  int roll_Left() {
    swap(num[1], num[4]);
    swap(num[1], num[3]);
    swap(num[1], num[5]);
    return num[0];
  }
};

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  while (cin >> n && n) {
    DICE d({1, 2, 6, 5, 3, 4});
    int ans = 1;

    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;

      if (s[0] == 'N') ans += d.roll_North();
      else if (s[0] == 'E') ans += d.roll_East();
      else if (s[0] == 'W') ans += d.roll_West();
      else if (s[0] == 'S') ans += d.roll_South();
      else if (s[0] == 'R') ans += d.roll_Right();
      else if (s[0] == 'L') ans += d.roll_Left();
    }

    cout << ans << '\n';
  }

  return (0);
}

