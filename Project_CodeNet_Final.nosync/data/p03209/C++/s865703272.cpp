#include <iostream>
using namespace std;


long long ans( long long L, long long X, long long* p, long long* total ){
    if( X == 1 && L >= 1 ){
        //cout << "a" << endl;
        return 0;
    }else if( 1 < X && X < total[L-1]+2 ){
        //cout << total[L-1]+2 << endl;
        return ans(L-1, X-1, p, total);
    }else if( X == total[L-1]+2 ){
        //cout << "c" << endl;
        return p[L-1] + 1;
    }else if( total[L-1]+2 < X && X < total[L] ){ 
        //cout << "d" << endl;
        return p[L-1] + 1 + ans(L-1, X-total[L-1]-2, p, total);
    }else return p[L];
}


int main(){

    long long N, X;
    cin >> N >> X;
    

    long long p[51], total[51], answer;
    p[0] = total[0] = 1;
    for( long long i = 0; i < N; i++ ){
        p[i+1] = 2 * p[i] + 1;
        total[i+1] = 2 * total[i] + 3;
    }

    answer = ans( N, X, p, total );
    
    cout << answer << endl;

    return 0;

}