#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
  int N,M;
  cin >> N >> M;

  list<pair<int, int> > all_edge;
  for (int i=0; i<M; i++) {
    int k,j;
    cin >> k>> j;
    all_edge.push_back(make_pair(k, j));
  }
  int numbers0[N-1];
  for (int i=2; i<N+1; i++) {
    numbers0[i-2] = i;
  }
  int ans = 0;
  do {
    int numbers[N];
    numbers[0] = 1;
    for (int i=1; i<N; i++) {
      numbers[i] = numbers0[i-1];
    }
    int i = 0;
    while (i<N-1) {
      int a = numbers[i];
      int b = numbers[i+1];
      if (numbers[i]<numbers[i+1]) {
        a = numbers[i];
        b = numbers[i+1];
      } else {
        b = numbers[i];
        a = numbers[i+1];
      }
      bool flag = false;
      for (pair<int, int> edge: all_edge) {
        if (edge.first == a && edge.second == b) {
          flag = true;
          break;
        }
      }
      if (flag) {
        ++i;
        continue;
      }
      break;
    }
    if (i == N-1) {
      ++ans;
    }
  } while(next_permutation(numbers0, numbers0+N-1));
  cout << ans << endl;

}