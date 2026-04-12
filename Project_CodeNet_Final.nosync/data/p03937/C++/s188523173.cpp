#include <bits/stdc++.h>
using namespace std;
const int N=233;

  int n,m,t;
  char a[N][N];
  int f[N][N];
int main()
{
  cin>>n>>m;
  for (int i=0;++i<=n;)
    scanf("%s",a[i]+1);
  f[1][1]=1;
	for (int i=0;++i<=n;)
    for (int j=0;++j<=m;)
      if (a[i][j]=='#')
        ++t,f[i][j]|=f[i-1][j]|f[i][j-1];
  if (t==n+m-1&&f[n][m])
    puts("Possible");
  else
    puts("Impossible");
  exit(0);
} 