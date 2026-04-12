#include<bits/stdc++.h>
using namespace std ;
#define MX 30

int main()
{
    int n ;
    int a[MX] ;
    int maxx ;
    int total ;
    while(cin >> n)
    {
        total = 0 ;
        maxx = 0 ;
        for(int i=0; i<n; i++)
        {
            cin >> a[i] ;
            if(a[i] >= maxx)
            {
                total++ ;
                maxx = a[i] ;
            }
        }
        cout << total << '\n' ;
    }
    return 0 ;
}
