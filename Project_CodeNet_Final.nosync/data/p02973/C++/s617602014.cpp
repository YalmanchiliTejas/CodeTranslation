# include <iostream>
# include <vector>
# include <algorithm>
# include <set>
# include <map>
# include <iomanip>
# include <string>
# include <cmath>

using namespace std;

const int N = 1e5 + 100;
int n, a[N];

int main()
{
    cin >> n;
    for( int i = 1; i <= n; i ++ ){
        cin >> a[i];
    }
    int l = 0, r = n;
    while ( r - l > 1 ){
        int m = ( l + r ) >> 1;
        int b[m] = {};
        b[0] = a[1];
        int len = 0, T = true;

        for( int i = 2; i <= n; i ++ ){
            int ll = -1, rr = len;

            while( rr - ll > 1 ){
                int mm = ( ll + rr ) >> 1;
                if( b[mm] < a[i] )rr = mm;
                else ll = mm;
            }

            if( b[rr] >= a[i] ){
                if( len == m-1){
                    T = false;
                    break;
                }
                b[++len] = a[i];
            }
            else{
                b[rr] = a[i];
            }
        }
        if( T ) r = m;
        else l = m;
    }
    cout << r;
    return 0;
}
