#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N;
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  deque<int64_t> P, Q;
  for (int i = 0; i < N; i++)
    P.push_back(A[i]);
  Q.push_front(P.front()); // 前に最小を入れる
  P.pop_front();
  Q.push_back(P.back()); // 後ろに最大を入れる
  P.pop_back();
  int64_t t = 0, ans = abs(Q.front() - Q.back());
  while (P.size() > 1)
  {
    if (t % 4 == 0)
    {
      ans += abs(P.back() - Q.front()); // 前に最大を入れる
      Q.emplace_front(P.back());
      P.pop_back();
    }
    else if (t % 4 == 1)
    {
      ans += abs(P.front() - Q.back()); // 後ろに最小を入れる
      Q.emplace_back(P.front());
      P.pop_front();
    }
    else if (t % 4 == 2)
    {
      ans += abs(P.front() - Q.front()); // 前に最小を入れる
      Q.emplace_front(P.front());
      P.pop_front();
    }
    else
    {
      ans += abs(P.back() - Q.back()); // 後ろに最大を入れる
      Q.emplace_back(P.back());
      P.pop_back();
    }
    t++;
  }
  if (!P.empty())
    ans += max(abs(P.front() - Q.front()), abs(P.front() - Q.back()));
  cout << ans << endl;
}
