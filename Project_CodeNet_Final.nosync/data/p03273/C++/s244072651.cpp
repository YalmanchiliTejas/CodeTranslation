#include <iostream>
#include <string>
using namespace std;
int main()
{
    char well[110][110];
    int rol[110],cow[110];
    fill(rol,rol+110,0);
    fill(cow,cow+110,0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin >> well[i][j];
        }
    }
    for(int i=0;i<n;++i)
    {
        int j;
        for(j=0;j<m;++j)
        {
            if(well[i][j]=='#')
                break;
        }
        if(j==m)
            rol[i]=1;
    }
    for(int i=0;i<m;++i)
    {
        int  j;
        for( j=0;j<n;++j)
            if(well[j][i]=='#')
                break;
        if(j==n)
            cow[i]=1;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            if(!rol[i]&&!cow[j])
                cout << well[i][j];
        if(!rol[i])
        cout << endl;
    }
}