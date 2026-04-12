#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <cmath>
#include <limits.h>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <stdio.h>
using namespace std;

long long MOD = 1000000007;

//全体  
long long func1( long long l ) {
    if ( l == 0 ) { return 1; }
    else {
        long long ret = 1;
        while ( l > 0 ) {
            ret *= 2;
            ret += 3;
            l--;
        }
        return ret;
    }
}


//P
long long func2( long long l ) {
    long long ret = func1(l);
    return (ret+1)/2;
}


long long func3( long long l, long long k ) {
    if ( l == 0 ) { return 1; }
    if ( k <= 1 ) { return 0; }

    long long s = func1(l);
    long long p = func2(l);
    
    if ( s == k ) { return p; }

    if ( (s+1)/2 == k ) { return func2(l-1)+1; }
    else if ( (s+1)/2 > k ) { return func3(l-1, k-1); }
    else if ( (s+1)/2 < k ) { return func2(l-1)+1+func3(l-1,k-(2+func1(l-1)) ); }
}


int main() {
    
    long long N;
    long long X;
    cin >> N >> X;

    if ( X <= 1 ) { cout << 0 << endl; return 0; }

    cout << func3( N, X ) << endl;

    return 0;
}