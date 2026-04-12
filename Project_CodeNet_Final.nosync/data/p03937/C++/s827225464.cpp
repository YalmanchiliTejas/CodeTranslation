#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char a[100][100]= {0};
int h1[]= {1,0};
int l1[]= {0,1};
int dp[100][100]= {0};
struct node
{
    int x;
    int y;
};
int main()
{
    int h,l;
    cin>>h>>l;
    for(int i=0; i<h; i++)
    {
        cin>>a[i];
    }
    queue<node>q;
    node a1;
    a1.x=0;
    a1.y=0;
    q.push(a1);
    dp[0][0]=1;
    while(!q.empty())
    {
        node p=q.front();
        q.pop();
        for(int i=0; i<=1; i++)
        {
            int x=p.x+h1[i];
            int y=p.y+l1[i];
            if(a[x][y]=='.')
                continue;
            if(x>=h||y>=l)
                continue;
            if(dp[x][y])
            {
                cout<<"Impossible"<<endl;
                return 0;
            }
            else
            {
                node o;
                o.x=x;
                o.y=y;
                dp[x][y]=1;
                q.push(o);
                break;
            }
        }
    }
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<l; j++)
        {
            if(a[i][j]=='#'&&dp[i][j]==0)
            {
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    cout<<"Possible"<<endl;
    return 0;
}
