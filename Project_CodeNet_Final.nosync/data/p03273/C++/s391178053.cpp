#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , m;
    cin >> n >> m ;
    char arr[n+1][m+1];
    for(int i = 1 ; i <=n ; i++)
    {
        for(int j = 1 ; j <=m ;j++)
        {
            cin >> arr[i][j];
        }
    }
    int r=0 , c=0;
    vector<int>dontCout,dont;
    for(int i = 1 ; i <=n ; i++)
    {
        r=0;
        for(int j = 1 ; j <=m ;j++)
        {
            if(arr[i][j]=='.')
                r++;
        }
        if(r==m)
        {
            dontCout.push_back(i);
        }
    }
    for(int i = 1 ; i <=m ; i++)
    {
        r=0;
        for(int j = 1 ; j <=n ;j++)
        {
            if(arr[j][i]=='.')
                r++;
        }
        if(r==n)
        {
            dont.push_back(i);
        }
    }
    int x=0 , y=0;
    for(int i = 1 ; i <=n ; i++)
    {
        if( binary_search(dontCout.begin(),dontCout.end(),i) )
        {
            continue;
        }
        for(int j = 1 ; j <=m;j++)
        {
            if(binary_search(dont.begin(),dont.end(),j))
                continue;
            cout << arr[i][j];
        }
        cout << "\n";
    }
    return 0;
}
