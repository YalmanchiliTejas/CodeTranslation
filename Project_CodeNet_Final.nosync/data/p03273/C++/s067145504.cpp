#include<bits/stdc++.h>

using namespace std;

int main()
{
    int d,p;
    cin >> d >> p;
    char dp[d][p];
    bool a[d]={0},b[p]={0};
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<p;j++)
        {
            cin >> dp[i][j];
            if(dp[i][j]=='#')
            {
                a[i]=1;
                b[j]=1;
            }
        }
    }
    bool h=0;
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<p;j++)
        {
            if(a[i]==1&&b[j]==1)
            {
                cout << dp[i][j];
                h=1;
            }
        }
        if(h)
        {
            cout << endl;
            h=0;
        }
    }
    return 0;
}
