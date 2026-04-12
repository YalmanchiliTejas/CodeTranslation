#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x;
  vector<int> seqs;
  cin >> n;
  while (n--)
  {
    cin >> x;
    int low = 0, high = int(seqs.size()) - 1, id = -1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (seqs[mid] >= x) low = mid + 1;
      else
      {
        id = mid;
        high = mid - 1;
      }
    }
    if (id >= 0) seqs[id] = x;
    else seqs.push_back(x);
  }
  cout << seqs.size() << endl;
}
