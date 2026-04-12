#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, a, b, c, x;
    while( cin >> n >> a >> b >> c >> x ) {
        if ( n == 0 && a == 0 && b == 0 && c == 0 && x == 0 )
            break;

        auto const res =
            [&]() -> int {
                vector<int> ys(n);
                for( int i=0; i<n; ++i ) 
                    cin >> ys[i];

                int current = x, next = x;
                int count = 0;
                for( int i=0; i<n; ++i ) {
                    for(;;) {
                        if ( count > 10000 )
                            return -1;

                        current = next;
                        next = ( a * current + b ) % c;                    

                        ++count;
                        if ( current == ys[i] )
                            break;
                    }
                }

                return count - 1;
            }();

        cout << res << endl;
    }
}