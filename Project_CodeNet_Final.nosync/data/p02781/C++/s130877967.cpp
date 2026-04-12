#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
string N;
int M;
int K;

int64_t recursive(int i, int k, bool f) {
  if (k == K) {
    return 1;
  } else if (i == M) {
    return 0;
  }
  int64_t ret = 0;
  int last = (N[i] - '0');
  if (!f) last = 9;
  for (int j = 0; j <= last; ++j) {
    // cout << "i=" << i << " N[i]=" << N[i] << " last=" << last << endl;
    int nk = (j == 0) ? k : k + 1;
    ret += recursive(i + 1, nk, f && (j == last));
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin >> N >> K;
  M = N.size();
  int64_t answer = recursive(0, 0, true);
  cout << answer << endl;
  return 0;
}
