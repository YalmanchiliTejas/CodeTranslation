#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <vector>
#include <cstdio>
#define  MAXN 110
using namespace std;
typedef long long LL;
vector <int> x, y;
int l[MAXN], t[MAXN], r[MAXN], b[MAXN]; 
LL map[110][110];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void dfs (int yy,int xx,LL cc)
{
     if (map[yy][xx] != cc) return; 
     map[yy][xx] = -1;
     for (int i=0;i<4;++i)
     {
         int xxx = xx+dx[i];
         int yyy = yy+dy[i];
         if (0<=xxx&&xxx<x.size()&&0<=yyy&&yyy<y.size())    
            dfs (yyy,xxx,cc);
     }    
}
int main(void)
{
    int n, ans;
    while ( scanf("%d",&n)==1 && n )
    {
          x.clear();
          y.clear();
          x.push_back(-1);
          y.push_back(-1);
          for (int i=0;i<n;++i)
          {
              scanf ("%d%d%d%d",l+i,t+i,r+i,b+i);    
              x.push_back(l[i]);
              x.push_back(r[i]);
              y.push_back(t[i]);
              y.push_back(b[i]);              
          }          
          sort (x.begin(),x.end());          
          x.erase(unique(x.begin(),x.end()),x.end());          
          sort (y.begin(),y.end());
          y.erase(unique(y.begin(),y.end()),y.end());
          memset (map,0,sizeof(map));
          for (int i=0;i<n;++i)
          {
              l[i] = lower_bound(x.begin(),x.end(),l[i]) - x.begin();    
              r[i] = lower_bound(x.begin(),x.end(),r[i]) - x.begin();    
              t[i] = lower_bound(y.begin(),y.end(),t[i]) - y.begin();    
              b[i] = lower_bound(y.begin(),y.end(),b[i]) - y.begin();    
              for (int j=b[i];j<t[i];++j)
              for (int k=l[i];k<r[i];++k) map[j][k] |= (1LL<<i);
          }
          ans = 0;
          for (int i=0;i<y.size();++i)
          for (int j=0;j<x.size();++j)
              if (map[i][j] >= 0) 
              {
                 dfs(i,j,map[i][j]); 
                 ans++;            
              }
          printf ("%d\n",ans);    
    }
    return 0;    
}