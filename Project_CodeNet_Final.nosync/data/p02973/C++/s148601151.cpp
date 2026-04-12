#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

#define MAX_N 100005

int N;
int A[MAX_N];
vector<int> colors;

int main() {
  cin >> N;
  int n;
  rep(i, N) cin >> A[i];
  rep(i, N) {
    auto it = lower_bound(colors.rbegin(), colors.rend(), A[i]);
    if(it == colors.rbegin()) {
      colors.push_back(A[i]);
    } else {
      *(--it) = A[i];
    }
  }
  cout << colors.size() << endl;
  return 0;
}
