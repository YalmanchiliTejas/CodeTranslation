#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    double n2;

    cin >> n;

    n2 = n;
    int bit[n];
    int selection[n];

    for( int i = 0; i < n; i++ )
    {
        bit[i] = i;
        selection[i] = 0;
    }
    
    for( int i = 0; i < pow( 2, n2 ); i++ )
    {
        int x = i;
        int j = 0;
        while( x > 1 )
        {
            selection[j] = x % 2;
            j++;
            x = x / 2;
        }
        selection[j] = x;

        cout << i << ":";
        for( int k = 0; k < n; k++ )
            if( selection[k] == 1 )
                cout << " " << bit[k];
        cout<< endl;
    }
    return 0;
}
