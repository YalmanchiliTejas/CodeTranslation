#include<iostream>
using namespace std;

int main()
{
    int n, a[100], b[100];

    cin >> n;

    for( int i = 0; i < n; i++ )
        cin >> a[i];

    int max = 0;
    bool judge= true;
    while( judge )
    {
        max++;
        for( int i = 0; i < n; i++ )
            b[i] = a[i];

        for( int i = 0; i < n - 1; i++ )
        {
            b[0] -= max;
            if( b[0] < 0 )
            {
                judge = false;
                break;
            }
            b[0] += b[i+1];
        }
    }

    cout << max - 1 << endl;

    return 0;
}
