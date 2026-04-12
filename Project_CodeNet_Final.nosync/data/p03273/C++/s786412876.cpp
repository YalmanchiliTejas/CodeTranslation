#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int h, w;
    char bor[105][105];
    bool val[105][105], ok=true;
    memset(val, true, sizeof(val));
    cin>>h>>w;
    for (int i=0; i<h; i++) for (int j=0; j<w; j++) cin>>bor[i][j];
    for (int i=0; i<h; i++)
    {
        ok=true;
        for (int j=0; j<w; j++) if (bor[i][j]!='.') ok=false;
        if (ok) for (int j=0; j<w; j++) val[i][j]=false;
    }
    for (int i=0; i<w; i++)
    {
        ok=true;
        for (int j=0; j<h; j++) if (bor[j][i]!='.' && val[j][i]) ok=false;
        if (ok) for (int j=0; j<h; j++) val[j][i]=false;
    }
    for (int i=0; i<h; i++)
    {
        ok=false;
        for (int j=0; j<w; j++)
        {
            if (val[i][j]) { cout<<bor[i][j]; ok=true; }
        }
        if (ok) cout<<endl;
    }
    return 0;
}
