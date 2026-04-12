#include <iostream>
#define REP(i, a, n) for(int i = a; i < n; i++)
using namespace std;


int n, c, a[100001], cnt;

int main(void) {
  while(cin >> n, n != 0) {
    REP(i, 1, n + 1) {
      cin >> c;

      if(i % 2 == 1) {
        a[i] = c;
      } else {
        a[i] = c;
        for(int j = i - 1; j >= 1 && a[j] != c; j--) {
          a[j] = c;
        }
      }
    }

    cnt = 0;
    REP(i, 1, n + 1) {
      if(a[i] == 0) cnt++;
    }

    cout << cnt << endl;
  }
  return 0;
}