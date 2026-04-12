#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f

#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
int n,m;

int main()
{
    #ifdef __LOCAL__
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif
    cin>>n>>m;
    if(n==m)
        cout<<"Yes";
    else
        cout<<"No";
    
    
    return 0;
}