#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> c(N);
  for (int i = 0; i < N; i++)
  {
    cin >> c.at(i);
  }
  deque<int> dq;
  dq.push_back(c.at(0));
  for (int i = 1; i < N; i++)
  {
    int p = lower_bound(dq.begin(), dq.end(), c.at(i)) - dq.begin();
    if (p)
    {
      p--;
      dq.at(p) = c.at(i);
    }
    else
    {
      dq.push_front(c.at(i));
    }
  }
  cout << dq.size() << endl;
}