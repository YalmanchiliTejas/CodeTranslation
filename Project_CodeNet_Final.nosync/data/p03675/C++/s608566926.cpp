#include<bits/stdc++.h>
using namespace std;
int a[200009];
int vis[200009];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
memset(vis,0,sizeof(vis));
        for(int i=n;i>0;i-=2)
        {
            cout<<a[i]<<" ";
            vis[i]=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                cout<<a[i]<<" ";
            }
        }


}
