#include <iostream>
#include <algorithm>
using namespace std;
int a[200005], sorted[200005];
int main()
{
    int n;
    cin >> n;
    for ( int i = 1; i <= n; i++ )
    {
        cin >> a[i];
        sorted[i] = a[i];
    }
    sort(sorted+1, sorted+1+n);
    int x = 0;
    if ( sorted[n/2] == sorted[n/2 + 1] )
    {
        for ( int i = 1; i <= n; i++ )
        {
            cout << sorted[n/2] << endl;
        }
    }
    else
    {
        for ( int i = 1; i <= n; i++ )
        {
            if ( a[i] <= sorted[n/2] )
            {
                cout << sorted[n/2 + 1] << endl;
            }
            else
            {
                cout << sorted[n/2] << endl;
            }
        }
    }
}