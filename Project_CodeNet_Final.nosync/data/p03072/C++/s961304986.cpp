#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>vec(N);
  int ans = 0;
  
  for (int i = 0; i < N; i++)
  {
    cin >> vec.at(i);
  }
  
  for (int i = 0; i < N; i++)
  {
    bool res = true;
    for (int j = 0; j < i; j++)
    {
      if (vec.at(i) - vec.at(j) < 0)
      {
        res = false;
      }
    }
    if (res == true)
    {
      ans++;
    }
  }
  
  cout << ans << endl;
}