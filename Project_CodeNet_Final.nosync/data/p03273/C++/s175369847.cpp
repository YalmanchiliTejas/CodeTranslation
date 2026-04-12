#include <bits/stdc++.h>

using namespace std;

int row[102] , col[102] ;

int main()
{
    int n , m ;
    cin>>n>>m ;
    char arr[n+1][m+1] ;
    for(int i = 1 ; i <= n ; ++i)
    {
        for(int j = 1 ; j <= m ; ++j)
        {
             cin>>arr[i][j] ;
             row[i] += (arr[i][j] == '.');
             col[j] += (arr[i][j] == '.');
        }
    }
    for(int i = 1 ; i <= n ; ++i)
    {
        if(row[i] == m)
            continue;
        int cnt = 0 ;
        for(int j = 1 ; j <= m ; ++j)
        {
             if(col[j] ==n)
             {
                 cnt++;
                 continue;
             }
             cout<<arr[i][j];
        }
        if(cnt != m)
            cout<<"\n";
    }
    return 0 ;
}
