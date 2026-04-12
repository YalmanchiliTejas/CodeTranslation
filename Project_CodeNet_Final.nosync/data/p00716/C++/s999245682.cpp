#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main( void )
{
    int m;
    cin >> m;

    for ( int l = 0; l < m; l++ ) {
        int answer = 0;
        int init, years, n;
        cin >> init >> years >> n;
        for ( int i = 0; i < n; i++ ) {
            int A = init;
            int type, fee;
            double x;
            cin >> type >> x >> fee;

            if ( type ) {
                for ( int j = 0; j < years; j++ ) {
                    int B = (int)floor( A * x );
                    A = A + B - fee;
                }
            } else {
                int r = 0;
                for ( int j = 0; j < years; j++ ) {
                    int B = (int)floor( A * x );
                    A -= fee;
                    r += B;
                }
                A += r;
            }
            answer = max( answer, A );
        }
        cout << answer << endl;
    }
    return 0;
}