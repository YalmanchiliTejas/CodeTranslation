#include <iostream>
#define REP(i, a, n) for(int i = ((int) a); i < ((int) n); i++)
using namespace std;

int N, A, B, C, X, Y[200];

int main(void) {
  while(cin >> N >> A >> B >> C >> X, N) {
    REP(i, 0, N) cin >> Y[i];

    int ans = 0, k = 0;
    while(ans <= 10000) {
      if(X == Y[k]) {
        k++;
        if(k == N) break;
      }
      X = (((A % C) * X) % C + B) % C;
      ans++;
    }
    cout << (ans <= 10000 ? ans : -1) << endl;
  }
  return 0;
}