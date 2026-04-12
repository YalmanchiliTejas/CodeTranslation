#include<cstdio>
#include<queue>
#include<utility>
#include<cstring>
#include<stack>
#include<algorithm>
#include<cmath>
#define INF 2147483647
#define REP(i,n) for(int i=0;i<(int)(n);i++)
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
using namespace std;
int main()
{
  int X,Y,Z,mod;
  scanf("%d %d %d",&X,&Y,&Z);
  mod = X % (Z+Y);
  if(mod >= Z)
    mod = 0;
  else
    mod = -1;
  printf("%d\n",X/(Z+Y) + mod);
  return 0;
}
