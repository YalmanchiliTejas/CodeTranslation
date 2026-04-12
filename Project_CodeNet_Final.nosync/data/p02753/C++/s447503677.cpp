#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long sum_of_onbit(vector<long> vec, long n, long i)
{
  long result = 0;
  long bitOne = 1;
  for (long j = 0; j < n; j++)
  {
    if (i & (1L << j))
    {
      result += vec[j];
    }
  }
  return result;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  if (s == "AAA" || s == "BBB")  {
      cout << "No" << endl;
      exit(0);
  }
  cout << "Yes" << endl;
}
