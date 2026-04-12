#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h,w,n;
    char a[105][105];
    set<int> x,y;
    cin >> h  >> w;
    for(int i = 0;i < h;i++)
        scanf("%s",a[i]);

    for(int i = 0;i < h;i++)
    {
        for(int j = 0;j < w;j++)
        {
            if(a[i][j]=='#')
            {
                x.insert(i);
                y.insert(j);
            }
        }
    }
    set<int>::iterator ix;
    set<int>::iterator iy;
    for(ix= x.begin();ix!=x.end();ix++)
    {
        for(iy=y.begin();iy!=y.end();iy++)
        {
            cout<<a[*ix][*iy];
        }
        cout << endl;
    }
}
