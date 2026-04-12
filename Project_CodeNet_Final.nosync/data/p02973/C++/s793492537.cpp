#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
// using Graph = vector<vector<Edge>>;
using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<ll> A(N);
  for (auto &it : A)
    cin >> it;
  deque<ll> ans;
  for (int i = 0; i < N; i++)
  {
    int idx = lower_bound(ans.begin(), ans.end(), A[i]) - ans.begin();
    if (idx == 0)
    {
      ans.push_front(A[i]);
    }
    else
    {
      idx--;
      ans[idx] = A[i];
    }
  }
  cout << ans.size() << endl;
  return 0;
}
