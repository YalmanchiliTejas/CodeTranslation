#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int main()
{
  int N, A;
  cin >> N;
  vector<int> color_list(0);
  color_list.push_back(2);
  for (int i = 0; i < N; ++i)
  {
    cin >> A;
    A = -A;
    int index = lower_bound(color_list.begin(), color_list.end(), A + 1) - color_list.begin();
    if (index == color_list.size())
    {
      color_list.push_back(A);
    }
    color_list.at(index) = A;
  }
  cout << color_list.size() << endl;
}
