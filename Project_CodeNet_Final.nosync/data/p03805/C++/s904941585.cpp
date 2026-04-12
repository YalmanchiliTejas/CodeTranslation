#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <array>
#include <queue>
#include <stack>
#include <set>
#include <utility>
using namespace std;

int main() {
  int N, M; cin >> N >> M;
  set<pair<int,int>> Se;
  for (int i = 0; i < M; i++) {
    pair<int,int> p;
    cin >> p.first >> p.second;
    Se.insert(p);
  }
  set<int> S2;
  for (auto it = Se.begin(); it != Se.end(); ++it) {
    if ((*it).first == 1)
      S2.insert((*it).second);
  }
  vector<int> V;
  for (int i = 1; i <= N; i++)
    V.push_back(i);
  int countOk = 0;
  do {
    if (V[0] != 1) {
      break;
    }
    if (S2.count(V[1]) == 1) {
      /*for (int i = 0; i < M-1; i++) {
        cout << V[i] << " ";
      }
      cout << V[M-1] << endl;*/
      int countPath = 0;
      for (int i = 0; i < N-1; i++) {
        int f = min(V[i],V[i+1]);
        int s = max(V[i],V[i+1]);
        countPath += Se.count(make_pair(f, s));
      }
      countOk += (countPath == N-1);
      //cout << countOk << endl;
    }
  } while (next_permutation(V.begin(), V.end()));
  cout << countOk << endl;
}
