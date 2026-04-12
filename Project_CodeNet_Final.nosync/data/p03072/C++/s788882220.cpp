#include "bits/stdc++.h"
using namespace std;

int N;

class bintree {
public:
  bintree(int n) : buf(new int[n]) {
    for (int i = 0; i < n; i++)
      buf[i] = 0;
  }
  int *buf;
};

int main(int argc, char **argv) {
  cin >> N;
  int H[N];
  int i, cnt = 0, maxhight = 0;

  for (i = 0; i < N; i++) {
    cin >> H[i];
    if (maxhight <= H[i]) {
      maxhight = H[i];
      cnt++;
    }
  }
  cout << cnt << endl;

  return 0;
}
