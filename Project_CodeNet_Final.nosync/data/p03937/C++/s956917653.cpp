#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        getchar();
        for (int j=1;j<=m;j++)
        {
            char ch=getchar();
            if (ch=='#') cnt++;
        }
    }
    puts((cnt == n+m-1)?"Possible":"Impossible");
    return 0;
}