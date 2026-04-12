#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  long long N, X, M;
  cin >> N >> X >> M;

  long long sum = 0;

  long long a = X;

  vector<long long> times_(M);
  vector<long long> sum_(M);
  vector<long long> num_(M);

  for (int i = 2; i < M; i++)
  {
    long long t = 1;
    long long s = 0;
    long long b = i;
    while (b * b < M)
    {
      s += b;
      b = b * b;
      t++;
    }
    s += (b % M);
    sum_[i] = s;
    num_[i] = b * b % M;
    times_[i] = t;
  }

  vector<long long> before_s(M, -1);
  vector<long long> before_i(M, -1);
  vector<long long> loop_s(M, -1);
  vector<long long> loop_i(M, -1);

  for (long long i = 0; i < N;)
  {
    if (loop_i[a] > 0)
    {
      if (N - i > loop_i[a])
      {
        long long nn = (N - i) / loop_i[a];
        i += loop_i[a] * nn;
        sum += loop_s[a] * nn;
        continue;
      }
    }
    else
    {
      if (before_i[a] >= 0)
      {
        loop_i[a] = i - before_i[a];
        loop_s[a] = sum - before_s[a];
      }
      else
      {
        before_i[a] = i;
        before_s[a] = sum;
      }
    }

    if (a == 0)
      break;
    else if (a == 1)
    {
      sum += (N - i);
      break;
    }

    if (N - i >= times_[a])
    {
      sum += sum_[a];
      i += times_[a];
      a = num_[a];
    }
    else
    {
      long long b = a * a % M;
      sum += b;
      a = b;
      i++;
    }
  }

  cout << sum << endl;

  return 0;
}
