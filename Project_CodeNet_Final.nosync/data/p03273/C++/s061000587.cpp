#include <iostream>
#include <set>

using namespace std;

char grid[105][105];
int idel[105];
int jdel[105];
int H, W;

bool checki(int ith)
{
    for (int j=0; j<W; j++)
    {
        if (grid[ith][j]=='#')
            return false;
    }
    return true;
}

bool checkj(int jth)
{
    for (int i=0; i<H; i++)
    {
        if (grid[i][jth]=='#')
            return false;
    }
    return true;
}

int main() {
    cin >> H >> W;
    for (int i=0; i<H; i++)
    {
        for (int j=0; j<W; j++)

        {
            cin >> grid[i][j];
        }
    }
    int m = H>W ? H : W;
    for (int i=0; i<m; i++)
    {
        if (checki(i))
        {
            idel[i]=1;
        }
        if (checkj(i))
        {
            jdel[i]=1;
        }
    }

    for (int i=0; i<H; i++)
    {
        for (int j=0; j<W; j++)
        {
            if ( !(idel[i]==1 || jdel[j]==1))
                cout << grid[i][j];
        }
        if (idel[i]!=1)
            cout << "\n";
    }
    return 0;
}