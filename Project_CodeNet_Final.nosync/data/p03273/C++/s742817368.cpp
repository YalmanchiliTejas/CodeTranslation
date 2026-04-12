#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int h,w,i,j;
    cin>>h>>w;
    char a[h][w];
    int row[h]={0},col[w]={0};
    for (i=0;i<h;i++)
    {
        for (j=0;j<w;j++)
        {
            cin>>a[i][j];
            if (a[i][j]=='#')
            {
                row[i]++;
                col[j]++;
            }
        }
    }
    for (i=0;i<h;i++)
    {
        if (row[i]!=0)
        {
            for (j=0;j<w;j++)
            {
                if (col[j]!=0)
                    cout<<a[i][j];
            }
            cout<<endl;
        }
    }
}