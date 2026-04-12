#include <iostream>

using std::cin;
using std::cout;
using std::endl;

static int N, M;
static bool connected[8][8] = {false};
static int count[8][256];

static int
solve_r(int cur, int state)
{
  int c = count[cur][state];
  if (c != 0)
  {
    c--;
  }
  else
  {
    if (state == 0)
    {
      c = 1;
    }
    else
    {
      c = 0;
      for (int next = 0, bit = 1; next < N; next++, bit <<= 1)
      {
        if (connected[cur][next] && (state & bit) != 0)
        {
          c += solve_r(next, state & ~bit);
        }
      }
    }
    count[cur][state] = c + 1;
  }
  return c;
}

static int
solve()
{
  return solve_r(0, (1 << N) - 2);
}

int
main()
{
  cin >> N >> M;
  for (int m = 0; m < M; m++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    connected[a][b] = true;
    connected[b][a] = true;
  }
  cout << solve() << endl;
  return 0;
}
