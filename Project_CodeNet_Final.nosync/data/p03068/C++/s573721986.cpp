#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, K;
  string S;
  cin >> N >> S >> K;
  for (int i = 0; i < N; i++)
    cout << (S.at(i) == S.at(K - 1) ? S.at(i) : '*');
  cout << endl;
}