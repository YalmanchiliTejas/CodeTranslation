#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<string>
using namespace std;
#define rep2(x,from,to) for(long long x=from;x<to;x++)
#define rep(x,to) rep2(x,0,to)
long long n;
long long a[200006];
long long dpe[200006][2];//last ari 1
int main()
{
    cin>>n;
    rep(i,n)cin>>a[i];
    for(long long i=2;i<=n;i+=2)
    {
        if(i==2)
        {
            dpe[2][0]=a[0];
            dpe[2][1]=a[1];
        }
        else
        {
            dpe[i][0]=dpe[i-2][0]+a[i-2];
            dpe[i][1]=max(dpe[i-2][0],dpe[i-2][1])+a[i-1];
        }       
    }
    if(n%2==0)
    {
        cout<<max(dpe[n][1],dpe[n][0])<<endl;
        return 0;
    }
    for(long long i=3;i<=n;i+=2)
    {
        if(i==3)
        {
            dpe[i][0]=max(a[0],max(a[1],a[2]));

        }
        else
        {
            dpe[i][0]=max(dpe[i-1][1],dpe[i-1][0]);
            dpe[i][0]=max(dpe[i][0],dpe[i-2][0]+a[i-1]);
        }
    }
    cout<<dpe[n][0]<<endl;

    return 0;
}