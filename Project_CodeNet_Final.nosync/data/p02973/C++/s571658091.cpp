#include<bits/stdc++.h>
using namespace std;

#define INF 2000000000

int a[100005] ;

int lis(int n)
{
    vector <int> l ;
    for(int i=0 ; i<=n ; i++) l.push_back( INF ) ;
    l[0] = -INF ;

    int ans = 0 ;

    for(int i=1 ; i<=n ; i++)
    {
        int idx = upper_bound( l.begin() , l.end() , a[i] ) - l.begin() ;
        ans = max(ans,idx) ;
        l[idx] = a[i] ;
    }
    return ans ;
}

int main()
{
    int n ;
    scanf("%d",&n) ;

    for(int i=1 ; i<=n ; i++) scanf("%d",&a[n-i+1]) ;

    printf("%d\n" , lis(n) ) ;

    return 0 ;
}

