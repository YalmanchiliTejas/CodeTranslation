#include <bits/stdc++.h>

using namespace std;

void solve()
{
  deque< int > q;
  int N;
  cin >> N;

  for(int i = 0; i < N; i++) {
    int A;
    cin >> A;
    if(i & 1) {
      if(N & 1)q.emplace_back(A);
      else q.emplace_front(A);
    } else {
      if(N & 1)q.emplace_front(A);
      else q.emplace_back(A);
    }
  }

  for(auto &p : q) cout << p << " ";
  cout << endl;

}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
