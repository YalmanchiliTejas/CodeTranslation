#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;
char m[105][105];
int main()
{
    int h, w;
    while(~scanf("%d%d", &h, &w))
    {
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                cin >> m[i][j];
        bool H[105], W[105];
        memset(H, 0, sizeof(H));
        memset(W, 0, sizeof(W));
        for(int i = 0; i < h; i++)
        {
            bool f = 1;
            for(int j = 0; j < w && f; j++)
            {
                if(m[i][j] == '#')
                    f = 0;
            }
            H[i] = f;
        }
        for(int j = 0; j < w; j++)
        {
            bool f = 1;
            for(int i = 0; i < h; i++)
            {
                if(m[i][j] == '#')
                    f = 0;
            }
            W[j] = f;
        }
        for(int i = 0; i < h; i++)
        {
            if(H[i])
                continue;
            for(int j = 0; j < w; j++)
            {
                if(W[j])
                    continue;
                cout<<m[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
