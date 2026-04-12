#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, color = 0;
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  vector<priority_queue<int64_t>> vpq(N + 1);
  multimap<int64_t, int64_t> mp; // top, color
  vpq.at(0).push(A[0]);
  mp.insert({A[0], 0});
  for (int i = 1; i < N; i++)
  {
    auto it = mp.lower_bound(A.at(i));
    if (it == mp.begin())
    {
      color++;
      vpq.at(color).push(A.at(i));
      mp.insert({A.at(i), color});
    }
    else
    {
      it--;
      auto p = *it;
      vpq.at(p.second).push(A.at(i));
      mp.erase(it);
      mp.insert({vpq.at(p.second).top(), p.second});
    }
  }
  cout << color + 1 << endl;
}