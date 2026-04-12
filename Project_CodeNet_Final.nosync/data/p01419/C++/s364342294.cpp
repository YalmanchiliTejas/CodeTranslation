#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#define nm 55
using namespace std;
int n, m, nrt, a[nm][nm], viz[nm][nm];
long long  pc[nm][nm], on[nm][nm], of[nm][nm], timp, viz2[nm][nm], prim, ultim, k, aux[nm*nm], nraux, ctmin[1005][2];
long long sol=0;
vector <long long> t[nm][nm];
struct punct
{
    int x, y;
} p[1005], d[]={{0,0},{1,0},{0,1},{-1,0},{0,-1}}, coada[nm*nm];
void citire()
{
    int i, j;
    char c[nm];

    cin>>n>>m>>nrt;

    for(i=0; i<=n+1; i++)
        a[i][0]=a[i][m+1]=-1;
    for(i=0; i<=m+1; i++)
        a[0][i]=a[n+1][i]=-1;

    for(i=1; i<=n; i++)
    {
        cin>>c;
        for(j=0; j<m; j++)
           if(c[j]!='.') a[i][j+1]=-1;
    }
     for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            cin>>pc[i][j];
     for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            cin>>on[i][j];
     for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            cin>>of[i][j];
     for(i=1; i<=nrt; i++)
        {
             cin>>p[i].x>>p[i].y;
             p[i].x++;
             p[i].y++;
        }
}
void drum(int x1, int y11, int x2, int y2)
{
    int i, j, x, y;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            viz2[i][j]=a[i][j];
    viz[x1][y11]= 1;
    viz2[x1][y11]=1;
    prim=ultim=k=1;
    coada[prim].x=x1; coada[prim].y=y11;
    while(k!=0)
    {
        for(i=1; i<=4; i++)
            if((!viz2[coada[prim].x+d[i].x][coada[prim].y+d[i].y])&&(a[coada[prim].x+d[i].x][coada[prim].y+d[i].y]!=-1))
        {
            viz[coada[prim].x+d[i].x][coada[prim].y+d[i].y]=1;
            viz2[coada[prim].x+d[i].x][coada[prim].y+d[i].y]=viz2[coada[prim].x][coada[prim].y]+1;
            ultim++;
            k++;
            coada[ultim].x=coada[prim].x+d[i].x;
            coada[ultim].y=coada[prim].y+d[i].y;
        }
        prim++;
        k--;
    }
    x=x2;
    y=y2;
    do
    {
       for(i=1; i<=4; i++)
        if(viz2[d[i].x+ x][d[i].y+y]== (viz2[x][y]-1))
          {
              t[x][y].push_back(timp+viz2[x][y]-1);
              x=d[i].x+ x;
              y=d[i].y+y;
              break;
          }
    }
    while((x1!=x)||(y11!=y));

    timp+=(viz2[x2][y2]-1);
}
void pd(int in1, int in2)
{
    ///aux- vect ce retine timpii la care ai trecut prin camera in1, in2
    ///ctmin[in_din_aux][0]= costul minim pt a iesi de a in_din_aux -a oara din camera in1, in2, lasan-o cu becul stins
    ///[1]= becul aprins
    int i;
    ctmin[1][0]=on[in1][in2]+of[in1][in2];
    ctmin[1][1]=on[in1][in2];
    for(i=2; i<=nraux; i++)
    {
        long long dif=(aux[i]-aux[i-1]);
        ctmin[i][0]=min(ctmin[i-1][0]+ on[in1][in2]+ of[in1][in2], ctmin[i-1][1]+ dif*pc[in1][in2] +of[in1][in2]);
        ctmin[i][1]=min(ctmin[i-1][0]+ on[in1][in2], ctmin[i-1][1]+ dif*pc[in1][in2]);
    }
    sol+=ctmin[nraux][0];
}
void solve()
{
    int i, j;
     t[p[1].x][p[1].y].push_back(0);
    for(i=1; i<nrt; i++)
        drum(p[i].x, p[i].y, p[i+1].x, p[i+1].y);//lee
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
           if(viz[i][j])
    {
         ///la prima trecere becul on si la ultima becul off
        nraux=0;
        for(auto it=t[i][j].begin(); it!=t[i][j].end(); ++it)
            {
                nraux++;
                aux[nraux]=*it;
            }
        pd(i, j);
    }
    cout<<sol<<"\n";
}
/*void afis()
{
    int i, j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(viz[i][j])
    {
        cout<<"room "<<i<<' '<<j<<"\n";
        for(auto it=t[i][j].begin(); it!=t[i][j].end(); ++it)
            cout<<(*it)<<' ';
        cout<<"\n";
    }
}*/
int main()
{
    citire();
    solve();
   // afis();
    return 0;
}

