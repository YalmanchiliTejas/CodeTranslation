#include <cstdio>
#include <cstring>

const int MaxN = 10;

int g[MaxN][MaxN];
int u[MaxN];
int n, m, res;

void go( int len, int last)
{
  
  if (len == n)
    return (void) res++;
    
  for (int i = 1; i < n; i++)
    if (u[i] == 0 && g[last][i])
    {
      u[i] = 1;
      go(len + 1, i);
      u[i] = 0;
    }
}


int main( void )
{
  while (scanf("%d %d", &n, &m) != EOF)
  {
    int a, b, i;
    memset (g, 0, sizeof g);
    for (i = 0; i < m; i++)
    {
      scanf("%d %d", &a, &b);
      g[a-1][b-1] = 1;
      g[b-1][a-1] = 1;
    }
    res = 0;
    memset (u, 0, sizeof u);
    u[0] = 1;
    go(1, 0);
    printf("%d\n", res);
  }
  return 0;
}