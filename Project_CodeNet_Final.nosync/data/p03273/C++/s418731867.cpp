#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <numeric>
//#include <bits/stdc++.h>

using namespace std;
const int INF = 1 << 30;

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    char x[n][m];
    for(int i = 0 ; i < n ;++i )
        for(int j = 0 ; j < m ;++j)
                cin>>x[i][j];
    int h[n];
    fill(h,h+n,1);
    int l[m];
    fill(l,l+m,1);
    for(int i = 0; i < n ;++i)
    {
        for(int j = 0 ; j < m ;++j)
            if(x[i][j]=='#')
                h[i]=0;
    }
    for(int j = 0 ; j < m ;++j)
        for (int i = 0; i < n; ++i)
        {
            if(x[i][j]=='#')
                l[j]=0;
        }
    for(int i = 0 ; i < n ;++i)
    {
        int flag=0;
        for(int j = 0 ;j<m;++j)
        {
            if(!h[i]&&!l[j])
            {    
                flag=1;
                cout<<x[i][j];
            }
        }
        if(flag)
            cout<<endl;
    }
    cout<<endl;
    return 0;
}