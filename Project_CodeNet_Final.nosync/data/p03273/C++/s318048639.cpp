#include<bits/stdc++.h>

using namespace std;

int vis[101][101];
int main()
{
    string s[101];
    int n , m , i , j , k ;

    cin >> n >> m ;

    for(i=0; i<n; i++)
        cin >> s[i];

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {


                int l = 0 , r = 0 ;
                for(k=0; k<n; k++)
                    if(s[k][j]=='#')
                        l = 1 ;
                for(k=0; k<m; k++)
                    if(s[i][k]=='#')
                        r = 1 ;
                if(l and r)
                    vis[i][j] = 1 ;

        }
    }

    for(i=0; i<n; i++)
    {
        int f = 0 ;
        for(j=0; j<m; j++)
        {
            if(vis[i][j])
                cout << s[i][j],f=1;
        }
        if(f)cout << '\n';
    }
}
