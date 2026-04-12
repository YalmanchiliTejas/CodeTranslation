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
  multimap<int64_t, int64_t> mp; // top, color
  mp.insert({A[0], 0});
  for (int i = 1; i < N; i++)
  {
    auto it = mp.lower_bound(A.at(i));
    if (it == mp.begin())
    {
      color++;
      mp.insert({A.at(i), color});
    }
    else
    {
      it--;
      auto p = *it;
      mp.erase(it);
      mp.insert({A.at(i), p.second});
    }
  }
  cout << color + 1 << endl;
}