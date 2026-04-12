#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h,w;
    cin >> h >> w;
    int a[h][w];
   for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
        {
        char s;
        cin >> s;
        if(s=='.')a[i][j] =1;
        else a[i][j] = 2;
        }
    int ans=0;

    for(int i=0;i<h;i++)
    {
    int cnt=0;
        for(int j=0;j<w;j++)
        {
        if(a[i][j]==1)cnt++;
        if(cnt == w)
            {
            for(int k=0;k<w;k++)
                {
                a[i][k] = 3;
                }
            }
        }
    }

for(int i=0;i<w;i++)
    {
    int cnt=0;
        for(int j=0;j<h;j++)
        {
        if(a[j][i]==1 || a[j][i] == 3)cnt++;
        if(cnt == h)
            {
            for(int k=0;k<h;k++)
                {
                a[k][i] = 3;
                }
            }
        }
    }

for(int i=0;i<h;i++)
{
    int cnt=0;
    for(int j=0;j<w;j++)
    {
    /*
    cout << a[i][j];
    */
    if(a[i][j]==3)continue;
    else if(a[i][j]==1)
        {
        cout << ".";
        cnt++;
        } 
        else 
        {
        cout << "#";
        cnt++;
        }
    }
    if(cnt !=0)cout << endl;
    cnt = 0;
}
return 0;
}