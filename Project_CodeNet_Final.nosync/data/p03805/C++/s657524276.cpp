#include <bits/stdc++.h>
using namespace std;

int N;
vector<bitset<8>> b(8, 0);

void loop(int bit, int *count, int point)
{
  bitset<8> flag(bit);
  flag.set(point);
  if (flag.count() == N)
  {
    (*count)++;
    return ;
  }
  for (int i = 0; i < N; i++)
  {
    if (!flag.test(i))
    {
      if (b[point].test(i))
        loop(flag.to_ullong(), count, i);
    }
  }
}

int main()
{
  int M, ai, aj, count = 0;

  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    cin >> ai >> aj;
    b[ai - 1].set(aj - 1);
    b[aj - 1].set(ai - 1);
  }
  loop(0, &count, 0);
  cout << count << endl;
}
