#include <iostream>
using namespace std;


long long ans( long long L, long long X, long long* p, long long* total ){
    if( X == 1 && L >= 1 ) return 0;
    else if( 1 < X && X < total[L-1]+2 ) return ans(L-1, X-1, p, total);
    else if( X == total[L-1]+2 ) return p[L-1] + 1;
    else if( total[L-1]+2 < X && X < total[L] ) return p[L-1] + 1 + ans(L-1, X-total[L-1]-2, p, total);
    else return p[L];
}


int main(){

    long long N, X;
    cin >> N >> X;
    

    long long p[51], total[51];
    p[0] = total[0] = 1;
    for( long long i = 0; i < N; i++ ){
        p[i+1] = 2 * p[i] + 1;
        total[i+1] = 2 * total[i] + 3;
    }
    
    cout << ans( N, X, p, total ) << endl;

    return 0;

}