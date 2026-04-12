#include <iostream>
#include <stack>

using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)

#define MAX_N 100001
int n;

int fetch() {
  int x; // 0 or 1 -> -1 or 1
  cin >> x;
  return x == 0 ? -1 : 1;
}
bool same_sgn(int x, int y) {
  return (x > 0 && y > 0) || (x < 0 && y < 0) || (x == 0 || y == 0);
}

int main() {
  while (true) {
    cin >> n;
    if (n == 0) break;

    stack<int> v;

    // head
    v.push(fetch());

    // tail
    for(int i=1; i<n; i++) {
      int x = fetch();
      // ?\???°
      // if ((i+1) % 2 == 1)
      int t = v.top();
      if (i % 2 == 0) {
        // ?¬?????????????
        if (same_sgn(x, t)) {
          v.pop();
          v.push(x + t);
        }
        else v.push(x);
      }
      // ??¶??°
      else {
        // ?¬?????????????
        if (same_sgn(x, t)) {
          v.pop();
          v.push(x + t);
        }
        else {
          // shuffle
          v.pop();
          int z = -t + x;

          // i = 2
          if (v.empty()) {
            v.push(z);
          }
         else {
            int u = v.top();

            // push???????????¨???????????????(z)??¨
            // ???????????????(u)??§??????????????????
            if (same_sgn(z, u)) {
              v.pop();
              v.push(z + u);
            }
            else {
              v.push(z);
            }
          }
        }
      }
    }
    int count = 0;
    while(!v.empty()) {
      int t = v.top();
      //cout << ' ' << t << endl; // DEBUG
      if (t < 0) count += (-t);
      v.pop();
    }
    cout << count << '\n';
  }
  return 0;
}