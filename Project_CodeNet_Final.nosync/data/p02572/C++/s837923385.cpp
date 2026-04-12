#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int64_t> A(N);
  int64_t total = 0;
  int64_t at = 0;
  int mod = 1000000007;
  
  for(int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  for(int i = N - 1; i > 0; i--)
  {
    at += A.at(i);
    at = at % mod;
    total += A.at(i - 1) * at % mod;
    total = total % mod;
  }
  cout << total << endl;
}