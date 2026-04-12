#include <bits/stdc++.h>
#define rep(a,s,d) for(int a=s;a<=d;a++)
using namespace std;
typedef long long ll;

char M[110][110];
bool hangok[110]={0},lieok[110]={0};

int main()
{
    int m,n;cin>>m>>n;
    rep(i,0,m)
    {
        cin>>M[i];
        rep(j,0,n)
        {
            if(M[i][j]=='#')
            {
                hangok[i]=1;lieok[j]=1;
            }
        }
    }
    rep(i,0,m)
    {
        if(!hangok[i]) continue;
        rep(j,0,n)
        {
            if(lieok[j])printf("%c",M[i][j]);
        }
        printf("\n");
    }
    return 0;
}
