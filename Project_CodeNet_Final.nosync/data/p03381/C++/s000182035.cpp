#include <bits/stdc++.h>
#define INT long long int
using namespace std;
INT n, a[200020], b[200020];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 0 ; i < n ; i++ ) cin>>a[i], b[i] = a[i];
    sort(b, b+n);
    for(int i = 0 ; i < n ; i++ )
    {
        if( a[i] > b[(n-1)/2] ) cout<<b[(n-1)/2]<<endl;
        else cout<<b[n/2]<<endl;
    }
    return 0;
}


