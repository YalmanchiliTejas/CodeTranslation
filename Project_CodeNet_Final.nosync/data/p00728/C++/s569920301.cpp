#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef vector <int> VI;

int main( void )
{
    int n, s;
    while ( cin >> n && n )
    {
        VI v(n);
        for ( int i = 0; i < n; i++ )
        {
            cin >> v[i];
        }
        sort( v.begin(), v.end() );
        
        double sum = 0.0;
        for ( int i = 1; i + 1 < n; i++ )
        {
            sum += v[i];
        }

        int score = (int)floor( sum / ( n - 2 ) );
        cout << score << endl;
    }

    return 0;
}