#include <bits/stdc++.h>
#define ll long long
#define eps 1e-9
#define PI 2 * acos (0.0)
using namespace std;

const int mod = 1000000000 + 7;

char ch[10][10];
bool bi[10][10];


int main()
{
  
    int a,b,c,d,e,x,y,z,n,m;

    scanf("%d %d", &n, &m);

    for(a=0; a<n; a++) scanf("%s", ch[a]);

    x = 0;
    y = 0;

    while(1)
    {
        bi[x][y]=true;
        //cout<<"now at "<<x<<","<<y<<endl;
        if(y+1>=m)
        {
            if(x+1>=n) break;
            if(ch[x+1][y]!='#') break;
            x++;
            continue;
        }
        if(ch[x][y+1]!='#')
        {
            if(x+1>=n) break;
            if(ch[x+1][y]!='#') break;
            x++;
            continue;
        }
        y++;
    }
    c=0;
    for(a=0;a<n;a++)
    {
        for(b=0;b<m;b++)
        {
            if(ch[a][b]=='#' && bi[a][b]==false) c++;
        }
    }

    if(!c) cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;

    return 0;
}
