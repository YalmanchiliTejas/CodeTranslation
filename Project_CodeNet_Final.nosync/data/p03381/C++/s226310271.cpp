#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++)
  {
    cin >> X.at(i);
    Y.at(i) = X.at(i);
  }
  
  sort(Y.begin(), Y.end());
  int m0 = Y.at(N / 2 - 1);
  int m1 = Y.at(N / 2);
  
  for (int i = 0; i < N; i++)
  {
    int ans;
    if (X.at(i) < m1) ans = m1;
    else ans = m0;
    cout << ans << endl;
  }
}