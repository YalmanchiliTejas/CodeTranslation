#include <bits/stdc++.h>

using namespace std;

int N;
int result = 1;
int main()
{
  cin >> N;
  vector<int> height(N);
  for (int i = 0; i < N; i++)
  {
    cin >> height[i];
  }

  for (int i = 1; i < N; i++)
  {
    bool view = true;
    for (int j = i - 1; j >= 0; j--)
    {
      if (height[j] > height[i])
      {
        view = false;
        break;
      }
    }
    // cout << ": " << height[i] << " : " << view << endl;
    if (view)
    {
      result++;
      // cout << height[i] << endl;
    }
    // cout << height[i] << endl;
  }

  cout << result;
}