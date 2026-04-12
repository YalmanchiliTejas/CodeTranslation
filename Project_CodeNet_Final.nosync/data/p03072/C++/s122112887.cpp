#include <bits/stdc++.h>
using namespace std;

int main()
{ 
  int n, sum_h = 1;
  bool flag;
  vector<int> h(20);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> h[i];
  for (int i = 1; i < n; i++)
  {
    flag = true;
    for (int j = 0; j < i; j++)
    {
      if (h[i] < h[j])
        flag = false;
    }
    if (flag)
      sum_h++;
  }
  cout << sum_h << endl;
}