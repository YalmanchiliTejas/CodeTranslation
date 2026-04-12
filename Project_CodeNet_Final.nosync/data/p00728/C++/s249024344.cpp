#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

void print_vec(vector<int> vec)
{
  cout << "[";
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec.at(i);
    if (i < vec.size() - 1)
    {
      cout << ", ";
    }
  }
  cout << "]...size: " << vec.size() << endl;
}

int main()
{
  vector<int> vec;

  while (true)
  {
    int n;
    cin >> n;
    if (n == 0)
    {
      break;
    }

    int least = 1001;
    int most = 0;
    int sum = 0;

    rep(i, n)
    {
      int x;
      cin >> x;
      least = min(least, x);
      most = max(most, x);
      sum += x;
    }

    int ave = (sum - least - most) / (n - 2);
    vec.push_back(ave);
  }

  for (auto &&i : vec)
  {
    printf("%d\n", i);
  }
}

