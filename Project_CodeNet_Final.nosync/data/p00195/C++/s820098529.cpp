#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A[5], B[5];

    while ( cin >> A[0] >> B[0], A[0] || B[0] ) {
        int maxp = 0;
        for ( int i = 1; i < 5; i++ ) {
            cin >> A[i] >> B[i];
            if ( A[maxp] + B[maxp] < A[i] + B[i] ) {
                maxp = i;
            }
        }
        cout << (char)('A' + maxp) << " " << A[maxp] + B[maxp] << endl;
    }

    return ( 0 );
}
