#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define local
//if you find any bug in my code, please tell me.
int graph[10][10],a[10];
int main()
{
#ifdef local
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    int n,m,i,ans=0;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a][b]=graph[b][a]=1;
    }
    for(i=0; i<n-1; i++) a[i]=i+2;
    sort(a,a+n-1);
    do
    {
        int now=1;
        for(i=0; i<n-1; i++)
        {
            if(!graph[now][a[i]]) break;
            now=a[i];
        }
        if(i==n-1) ans++;
    }while(next_permutation(a,a+n-1));
    cout<<ans<<endl;
    return 0;
}
