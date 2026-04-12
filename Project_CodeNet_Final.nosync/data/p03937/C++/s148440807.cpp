#include<bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
typedef vector< ll > vi ;
typedef pair<ll, ll > ii ;
int n , m ;
char a[9][9];
int dfs(int i , int j )
{
    if( i == n || j == m )
        return 0 ;
    if( a[i][j] =='.')
        return 0 ;
    int c1 = dfs(i+1,j) +1 ;
    c1 = max(c1 , dfs(i,j+1)+1);
    return c1 ;
}
int main()
{
    cin >> n >> m ;
    int x , y ;
    bool b = 0 ;
    int aux = 0 ;
    for(int i = 0 ; i < n ; i ++ )
        for(int j = 0 ; j < m ; j ++ ){
            cin >> a[i][j] ;
            if(a[i][j] =='#')
                aux++;
            if(a[i][j] == '#' && !b)
                x = i , y = j , b =1 ;
        }
    if(dfs(0,0) == aux)
        cout << "Possible";
    else
        cout << "Impossible";
}
