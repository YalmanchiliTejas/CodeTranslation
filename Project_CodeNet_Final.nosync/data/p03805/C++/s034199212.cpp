#include <cstdio>
#include <vector>
using namespace std;
vector <int> v[12];
int n,m,i,x,y,nr,sol;
bool s[12];
void  g (int x, int nr)
{
    int i;
    if (nr==n)
        sol++;
    for (i=0;i<v[x].size();i++)
    {
        if (s[v[x][i]]==false)
        {
            s[v[x][i]]=true;
            nr++;
            g(v[x][i],nr);
            nr--;
            s[v[x][i]]=false;
        }
    }
}
int main()
{
    scanf ("%d %d", &n, &m);
    for (i=1;i<=m;i++)
    {
        scanf ("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=2;i<=n;i++)
        s[i]=false;
    s[1]=true;
    g(1,1);
    printf ("%d", sol);
    return 0;
}
