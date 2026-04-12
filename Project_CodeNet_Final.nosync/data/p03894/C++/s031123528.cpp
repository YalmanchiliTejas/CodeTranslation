#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, Q;
  cin >> N >> Q;
  int latte[100000] = {}, malta[100000] = {};
  latte[0] = true;
  malta[0] = malta[1] = true;

  for(int i = 0; i < Q; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    swap(latte[x], latte[y]);
    swap(malta[x], malta[y]);

    if(x && latte[x - 1]) {
      malta[x] = true;
    }
    if(x + 1 < N && latte[x + 1]) {
      malta[x] = true;
    }

    if(latte[x]) {
      if(x) malta[x - 1] = true;
      if(x + 1 < N) malta[x + 1] = true;
    }

    if(latte[y]) {
      if(y) malta[y - 1] = true;
      if(y + 1 < N) malta[y + 1] = true;
    }


    if(y && latte[y - 1]) {
      malta[y] = true;
    }
    if(y + 1 < N && latte[y + 1]) {
      malta[y] = true;
    }

  }

  cout << count(malta, malta + N, true) << endl;
}